#pragma once
#include "Common.hpp"
#include "Memory.hpp"

namespace ER {
#pragma pack(1)
    struct EquipParamWepOff {
    public:
        uint8_t EquipParamWeaponOffset1; // 0x88
        uint8_t EquipParamWeaponOffset2; // 0x80
        uint8_t EquipParamWeaponOffset3; // 0x80
    };
#pragma(pop)
#pragma pack(1)
    struct EquipParamWeapon {
    public:

        uint8_t MaterialSetID; // 0x5C
        uint8_t ReinforceTypeID; // 0xDA
        uint8_t SwordArtsParamId; // 0x198
        uint8_t WepType; // 0x1A6
    };
#pragma(pop)
#pragma pack (1)
    struct EquipParamGemOff {
    public:
        uint8_t EquipParamGemOffset1; // 0x2BD8
        uint8_t EquipParamGemOffset2; // 0x80
        uint8_t EquipParamGemOffset3; // 0x80
    };
#pragma(pop)
#pragma pack (1)
    struct EquipParamGem {
    public:
        uint8_t canMountWep_Dagger; // 0x38
        uint8_t canMountWep_SwordPierce; // 0x39
        uint8_t canMountWep_SpearLarge; // 0x3A
        uint8_t canMountWep_BowSmall; // 0x3B
        uint8_t canMountWep_ShieldSmall; // 0x3C

    };
#pragma(pop)
#pragma pack (1)

    struct EquipParamProtectorOff1
    {
    public:
        uint32_t EquipParamProtectorOffset2; // 0x80
        uint32_t EquipParamProtectorOffset3; // 0x80 

    };
#pragma(pop)
#pragma pack(1)

    struct ParamTable
    {
    public:
        uint32_t ParamID; //0x0000 
        uint32_t Pad; //0x0004 
        uint64_t ParamOffset; //0x0008 
        char pad_0x0010[0x8]; //0x0010
        uint64_t nextParam; //0x0018 
        char pad_0x0020[0x20]; //0x0020
        uint64_t Param; //0x0040 
    }; 
#pragma(pop)
#pragma pack(1)

    struct HelmParam {
    public:
        char pad_0x0000[0x28]; //0x0000
        uint32_t SpEffect1; //0x0028 
        uint32_t SpEffect2; //0x002C 
        uint32_t SpEffect3; //0x0030

    };


#pragma(pop)


    class ParamRepo {
    public:
        uint64_t Base{};
        uint64_t Ptr{};
        uint64_t LastPtr{};
        ParamTable* ParamTble{}; //(ParamTable*)RPM<uintptr_t>(RPM<uintptr_t>(RPM<uintptr_t>(Ptr + 0xD0) + 0x80) + 0x80)
        HelmParam* HelmPram{};

        explicit ParamRepo();
        ~ParamRepo() noexcept = default;
        ParamRepo(ParamRepo const&) = delete;
        ParamRepo(ParamRepo&&) = delete;
        ParamRepo& operator=(ParamRepo const&) = delete;
        ParamRepo& operator=(ParamRepo&&) = delete;
        void Init();
        void Update();
        bool Valid();

    };


    inline std::unique_ptr<ParamRepo> g_ParamRepo;
}