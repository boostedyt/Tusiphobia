#include "pch.h"

#include "settings.h"

namespace Settings {
	namespace Movement {
		namespace NoClip {
			bool enabled = false;
			float speed = 5.0f;
		}

		bool infiniteStamina = false;
		float runSpeed = 3.0f;
		float walkSpeed = 1.6f;
		
	}


	namespace pickupgang {
		float raycastMaxDistance = 100.0f;
	}

	namespace Camera {
		float fieldOfView = 90.0f;
	}

	namespace Visual {
		namespace FullBright {
			bool enabled = false;
			SColor color = SColor::white;
			float range = 999.0f;
			float spotAngle = 360.0f;
			float intensity = 0.25f;
		}
		//std::string text;
		namespace ESP {
			namespace Ghost {
				bool bones = false;
				SColor color = SColor::red;
			}

			namespace Player {
				bool label = false;
				bool bones = false;

				SColor color = SColor::blue;
			}

			namespace EMF {
				bool label = false;
				bool showLevel = true;
				bool customColor = false;

				SColor color = SColor::green;
			}

			namespace CursedPosession {
				bool label = false;
				SColor color = SColor::orange;
			}

			namespace Fingerprint {
				bool label = false;
				SColor color = SColor::purple;
			}

			namespace Footstep {
				bool label = false;
				SColor color = SColor::purple;
			}

			namespace Bone {
				bool label = false;
				SColor color = SColor::yellow;
			//	text = "Bone";
			}

			namespace DeadBody {
				bool label = false;
				SColor color = SColor::white;
			}

			namespace DirtyWater {
				bool label = false;
				SColor color = SColor::brown;
			}

			namespace GhostWriting {
				bool label = false;
				SColor color = SColor::white;
			}
		}
	}

	namespace Info {
		namespace Ghost {
			namespace Show {
				bool type = false;
				bool evidence = false;

				bool name = false;
				bool age = false;
				bool gender = false;
				bool deathLength = false;

				bool shyness = false;
				bool favouriteRoom = false;
			}

			namespace Activity {
				float graphPoints[61] = {};

				namespace Show {
					bool hunting = false;
					bool strength = false;
					bool graph = false;
				}
			}
		}

		namespace Sanity {
			bool show = false;
		}
	}

	namespace Key {
		namespace GrabAutomatically {
			bool all = false;
			bool main = false;
			bool car = false;
			bool cabin = false;
		}
	}

	namespace CursedPosession {
		namespace OuijaBoard {
			char* customResponse = nullptr;
		}
	}
}
