#pragma once
//------------------------------------------------------------------------------
/**
    Simple Arena allocator used to allocate AnyFX symbols

    @copyright
    (C) 2024 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <vector>
namespace AnyFX
{

class Allocator
{
public:
    /// Construct allocator with block size
    Allocator(unsigned blockSize = 4096) 
        : blockSize(blockSize)
        , iterator(nullptr)
        , currentChunk(nullptr)
    {}

    ~Allocator()
    {
        for (size_t i = 0; i < this->retiredChunks.size(); i++)
            free(this->retiredChunks[i]);
        if (this->currentChunk)
            free(this->currentChunk);

        this->currentChunk = nullptr;
        this->iterator = nullptr;
        this->retiredChunks.clear();
    }

    /// Allocate object
    template <typename T, typename... ARGS> T* Alloc(ARGS... args)
    {
        if (sizeof(T) > this->blockSize)
        {
            T* buf = new T();
            this->retiredChunks.push_back(buf);
            this->currentChunk = nullptr;
            this->NewChunk();
            return buf;
        }
        else
        {
            if (this->iterator == nullptr)
                this->NewChunk();
            else
            {
                unsigned remainder = this->blockSize - unsigned(this->iterator - this->currentChunk);
                if (remainder < sizeof(T))
                    this->NewChunk();
            }
        }

        T* ret = new (this->iterator) T(args...);
        this->iterator += sizeof(T);
        return ret;
    }

    /// Allocate object
    char* Alloc(size_t size)
    {
        if (size > this->blockSize)
        {
            char* buf = new char[size];
            this->retiredChunks.push_back(buf);
            this->currentChunk = nullptr;
            this->NewChunk();
            return buf;
        }
        else
        {
            if (this->iterator == nullptr)
                this->NewChunk();
            else
            {
                unsigned remainder = this->blockSize - unsigned(this->iterator - this->currentChunk);
                if (remainder < size)
                    this->NewChunk();
            }
        }

        this->iterator += size;
        return this->iterator;
    }

    void NewChunk()
    {
        if (this->currentChunk != nullptr)
            this->retiredChunks.push_back(this->currentChunk);
        this->currentChunk = (char*)malloc(this->blockSize);
        this->iterator = this->currentChunk;
    };
private:
    char* currentChunk;
    char* iterator;
    std::vector<char*> retiredChunks;

    unsigned blockSize;
};

} // namespace AnyFX