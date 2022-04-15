#pragma once
#include "Common.hpp"
#include "Memory.hpp"

namespace ER {
#pragma pack(1)
    class ParamRepo {
    public:
        uint8_t TotalParamLength; // 0x0
        uint32_t NameOffset; // 0x10
        uint8_t TableLength; // 0x30
        uint64_t Base{};
        uint64_t Ptr{};
        uint64_t LastPtr{};
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
    
#pragma(pop)
    class EquipParamWepOff {
    public:
        uint8_t EquipParamWeaponOffset1; // 0x88
        uint8_t EquipParamWeaponOffset2; // 0x80
        uint8_t EquipParamWeaponOffset3; // 0x80
    };
#pragma pack (1)
    class EquipParamWeapon {
    public:
    
        uint8_t MaterialSetID; // 0x5C
        uint8_t ReinforceTypeID; // 0xDA
        uint8_t SwordArtsParamId; // 0x198
        uint8_t WepType; // 0x1A6
    };
#pragma(pop)
    class EquipParamGemOff {
    public:
        uint8_t EquipParamGemOffset1; // 0x2BD8
        uint8_t EquipParamGemOffset2; // 0x80
        uint8_t EquipParamGemOffset3; // 0x80
    };
#pragma pack(1)
    class EquipParamGem {
    public:
        uint8_t canMountWep_Dagger; // 0x38
        uint8_t canMountWep_SwordPierce; // 0x39
        uint8_t canMountWep_SpearLarge; // 0x3A
        uint8_t canMountWep_BowSmall; // 0x3B
        uint8_t canMountWep_ShieldSmall; // 0x3C

    };
#pragma(pop)
    inline std::unique_ptr<ParamRepo> g_ParamRepo;
    }
}
