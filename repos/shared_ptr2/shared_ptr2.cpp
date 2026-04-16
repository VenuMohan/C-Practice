// shared_ptr2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

struct Texture 
{
    Texture(int _mapCount, int _size, float _res)
    {
        mapCount = _mapCount;
        size = _size;
        res = _res;
    }

    ~Texture()
    {
        std::cout << "texture destroyed" << "\n";
    }
    int mapCount;
    int size;
    float res;
};

void PrintTextureDetails(const std::shared_ptr<Texture>& t)
{
    const Texture& tex = *t.get();
    std::cout << "map count: " << tex.mapCount << "\n";
    std::cout << "size: " << tex.size << "\n";
    std::cout << "res: " << tex.res << "\n";
}

void SetTextureDetails(const std::shared_ptr<Texture>& texPtr, const Texture& tex)
{
    Texture* t = texPtr.get();
    t->mapCount = tex.mapCount;
    t->res = tex.res;
    t->size = tex.size;
}


int main()
{
    // shared ptr is used quite a lot in sharing textures, audio etc

    //texture pool
    std::vector<std::shared_ptr<Texture>> texPool;

    std::shared_ptr<Texture> t1 = std::make_shared<Texture>(4, 512, 0.77);
    texPool.push_back(t1);

    std::shared_ptr<Texture> t2 = t1;
    std::cout << "ref count : " << t1.use_count() << "\n";

    SetTextureDetails(t2, { 5, 256, 0.67 });
    texPool.push_back(t2);
    PrintTextureDetails(t2);
    PrintTextureDetails(t1);

    t1.reset();
    std::cout << "ref count : " << t2.use_count() << "\n";

    t2.reset();
    std::cout << "ref count : " << t2.use_count() << "\n";

    // use lambda to erase from pool
    texPool.erase
    (
        std::remove_if(texPool.begin(), texPool.end(),
            [](const std::shared_ptr<Texture>& t)
            {
                return t.use_count() == 1;
            }),
        texPool.end()
    );
    

}

