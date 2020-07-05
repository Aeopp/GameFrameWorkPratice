#pragma once
#include "AActor.h"
#include "stdafx.h"

class APlayer :
    public AActor
{
public:
    APlayer();
    void Test();
private:
    std::weak_ptr<UCollision> _Collision;
    std::weak_ptr<UMesh> _Mesh;

    std::weak_ptr<UCollision> _Collision2;
    std::weak_ptr<UMesh> _Mesh2;

    std::weak_ptr<UCollision> _Collision3;
    std::weak_ptr<UMesh> _Mesh3;
};

