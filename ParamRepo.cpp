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
		ParamTble = (ParamTable*)RPM<uintptr_t>(RPM<uintptr_t>(RPM<uintptr_t>(Ptr + 0xD0) + 0x80) + 0x80);
		HelmPram = (HelmParam*)RPM<uintptr_t>(RPM<uintptr_t>(RPM<uintptr_t>(Ptr + 0xD0) + 0x80) + 0x80) + 0xC798;
	
	}

	bool ParamRepo::Valid()
	{
		return (Base != 0 && Ptr != 0);
	}
}