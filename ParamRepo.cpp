#include "ParamRepo.hpp"

namespace ER {
	ParamRepo::ParamRepo()
	{
		Init();
	}

	void ParamRepo::Init()
	{
		if (!Base) // Base should never change.
		{
			auto Sig = Signature("48 8B 0D ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 45 33 C0 BA 8E 00 00 00").Scan().Add(3).Rip().As<uint64_t>();

			if (!Sig)
				return;

			Base = Sig;
		}

		auto BasePtr = RPM<uint64_t>(Base);

		if (!BasePtr)
			return;

		Ptr = BasePtr;
		LastPtr = Ptr;

		Update();
	}

	void ParamRepo::Update()
	{
		if (!Base || !Ptr) {
			Init();
			return;
		}

		if (LastPtr != RPM<uint64_t>(Base)) {
			Ptr = 0;
			LastPtr = 0;
			return;
		}

		LastPtr = Ptr;
		//NameOffset = RPM<uint32_t>(Ptr + 0x10);
		//TableLength = RPM<uint32_t>(Ptr + 0x30);
		//TotalParamLength = RPM<uint32_t>(Ptr + 0x0);
		ParamRep = (EquipParamWeapon*)RPM<uint64_t>(Ptr + 0x80);
	}

	bool ParamRepo::Valid()
	{
		return (Base != 0 && Ptr != 0);
	}
}