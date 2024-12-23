#include "pch.h"

#include "gui.h"
#include "settings.h"

#pragma region main menu


void drawMainMenu() {
	static ImVec4 menuBackgroundColor = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // Default background color
	static float menuTransparency = 1.0f;                                // Menu transparency
	static float fontScale = 1.0f;                                       // Font scale

	if (ImGui::Begin("tusiphobia", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(menuBackgroundColor.x, menuBackgroundColor.y, menuBackgroundColor.z, menuTransparency));
		using namespace Settings;

		if (ImGui::BeginTabBar("MainTabs")) {

			// Movement Tab
			if (ImGui::BeginTabItem("Movement")) {
				using namespace Movement;

				if (ImGui::TreeNode("No Clip")) {
					using namespace NoClip;

					ImGui::Checkbox("Enabled", &enabled);
					ImGui::SliderFloat("Speed", &speed, 0.0f, 15.0f);


					if (SGhostAI::instance) {
						if (ImGui::Button("appear"))
							SGhostAI::instance->appear(2);

						if (ImGui::Button("look at nearest player"))
							SGhostAI::instance->lookAtNearestPlayer();

						if (ImGui::Button("disappear"))
							SGhostAI::instance->disappear();



						




						

						
					}

					ImGui::TreePop();
				}

				ImGui::Checkbox("Infinite Stamina", &infiniteStamina);
				ImGui::SliderFloat("Run Speed", &runSpeed, 0.0f, 15.0f);
				ImGui::SliderFloat("Walk Speed", &walkSpeed, 0.0f, 15.0f);


				
				/*ImGui::SliderFloat("Pickup Distance", &pickupgang::raycastMaxDistance, 0.0f, 100.0f);

				if (SGhostAI::instance) {
					if (ImGui::Button("appear"))
						SGhostAI::instance->appear(2);

					if (ImGui::Button("look at nearest player"))
						SGhostAI::instance->lookAtNearestPlayer();

					if (ImGui::Button("disappear"))
						SGhostAI::instance->disappear();
				}*/

				


				ImGui::EndTabItem();
			}


			

			// Visual Tab
			if (ImGui::BeginTabItem("Visual")) {
				using namespace Visual;

				if (ImGui::TreeNode("Full Bright")) {
					using namespace FullBright;

					ImGui::Checkbox("Enabled", &enabled);
					ImGui::ColorEdit3("Color", (float*)&color);
					ImGui::SliderFloat("Range", &range, 0.0f, 999.0f);
					ImGui::SliderFloat("Spot Angle", &spotAngle, 0.0f, 360.0f);
					ImGui::SliderFloat("Intensity", &intensity, 0.0f, 10.0f);


					

					ImGui::TreePop();
				}


				if (ImGui::TreeNode("Camera")) {
					using namespace Camera;

					if (ImGui::SliderFloat("Field of View", &fieldOfView, 30.0f, 140.0f, "%.1f"))
					{

						SCamera* camera = SCamera::getMain();

						if (!camera)
						{
							ImGui::Text("No main camera found!");
							return;
						}
						// Set the new FOV if the slider value changes
						camera->setFieldOfView(fieldOfView);
					}

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("ESP")) {
					using namespace ESP;

					if (ImGui::TreeNode("Ghost")) {
						using namespace Ghost;

						ImGui::Checkbox("Bones", &bones);
						ImGui::ColorEdit3("Color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("Player")) {
						using namespace Player;

						ImGui::Checkbox("Label", &label);
						ImGui::Checkbox("Bones", &bones);
						ImGui::ColorEdit3("Color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("EMF")) {
						using namespace EMF;

						ImGui::Checkbox("Label", &label);
						ImGui::Checkbox("Show Level", &showLevel);
						ImGui::Checkbox("Custom Color", &customColor);

						ImGui::BeginDisabled(!customColor);
						ImGui::ColorEdit3("Color", (float*)&color);
						ImGui::EndDisabled();

						ImGui::TreePop();
					}


					if (ImGui::TreeNode("fingerprint")) {
						using namespace Fingerprint;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("footstep")) {
						using namespace Footstep;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}


					if (ImGui::TreeNode("bone")) {
						using namespace Bone;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("dead body")) {
						using namespace DeadBody;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("dirty water")) {
						using namespace DirtyWater;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("ghost writing")) {
						using namespace GhostWriting;

						ImGui::Checkbox("label", &label);
						ImGui::ColorEdit3("color", (float*)&color);

						ImGui::TreePop();
					}

					// Additional ESP options (Cursed Possession, Fingerprint, etc.)
					if (ImGui::TreeNode("Cursed Possession")) {
						using namespace ESP::CursedPosession;

						ImGui::Checkbox("Label", &label);
						ImGui::ColorEdit3("Color", (float*)&color);

						ImGui::TreePop();
					}

					ImGui::TreePop();
				}

				ImGui::EndTabItem();
			}

			// Info Tab
			if (ImGui::BeginTabItem("Info")) {
				using namespace Info;

				if (ImGui::TreeNode("Ghost")) {
					using namespace Ghost;

					if (ImGui::TreeNode("Show")) {
						using namespace Show;

						if (ImGui::Button("Check All")) {
							type = true;
							evidence = true;
							name = true;
							age = true;
							gender = true;
							deathLength = true;
							shyness = true;
							favouriteRoom = true;
						}

						ImGui::Checkbox("Type", &type);
						ImGui::Checkbox("Evidence", &evidence);
						ImGui::Checkbox("Name", &name);
						ImGui::Checkbox("Age", &age);
						ImGui::Checkbox("Gender", &gender);
						ImGui::Checkbox("Death Length", &deathLength);
						ImGui::Checkbox("Shyness", &shyness);
						ImGui::Checkbox("Favourite Room", &favouriteRoom);

						ImGui::TreePop();
					}

					if (ImGui::TreeNode("activity")) {
						using namespace Activity;

						if (ImGui::TreeNode("show")) {
							using namespace Activity::Show;

							if (ImGui::Button("check all")) {
								hunting = true;
								strength = true;
								graph = true;
							}

							ImGui::Checkbox("hunting", &hunting);
							ImGui::Checkbox("strength", &strength);
							ImGui::Checkbox("graph", &graph);

							ImGui::TreePop();
						}

						ImGui::TreePop();
					}

					ImGui::TreePop();
				}

					
		


				if (ImGui::TreeNode("Sanity")) {
					using namespace Sanity;

					ImGui::Checkbox("Show", &show);

					ImGui::TreePop();
				}

				ImGui::EndTabItem();
			}

			// Key Tab
			if (ImGui::BeginTabItem("Key")) {
				using namespace Key;

				if (ImGui::TreeNode("Grab Automatically")) {
					using namespace GrabAutomatically;

					ImGui::Checkbox("All", &all);

					ImGui::BeginDisabled(all);
					ImGui::Checkbox("Main", &main);
					ImGui::Checkbox("Car", &car);
					ImGui::Checkbox("Cabin", &cabin);
					ImGui::EndDisabled();

					ImGui::TreePop();
				}

				for (SKey* key : SKey::notGrabbedKeys) {
					const char* keyType = "None";
					switch (key->getType()) {
					case SKeyType::Main: keyType = "Main"; break;
					case SKeyType::Car: keyType = "Car"; break;
					case SKeyType::Cabin: keyType = "Cabin"; break;
					}

					if (ImGui::Button(std::string("Grab ").append(keyType).c_str()))
						key->grab();
				}

				ImGui::EndTabItem();
			}


			if (ImGui::BeginTabItem("Settings")) {
				ImGui::Text("Customize Menu Appearance");

				ImGui::ColorEdit4("Background Color", (float*)&menuBackgroundColor);
				ImGui::SliderFloat("Transparency", &menuTransparency, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Font Scale", &fontScale, 0.5f, 2.0f, "%.2f");

				ImGui::Text("Font Adjustments:");
			//	if (ImGui::Button("Increase Font Size"))
					//ImGui::GetIO().FontGlobalScale = std::min(2.0f, fontScale += 0.1f);
			//	ImGui::SameLine();
				//if (ImGui::Button("Decrease Font Size"))
				//	ImGui::GetIO().FontGlobalScale = std::max(0.5f, fontScale -= 0.1f);

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}

		ImGui::End();
	}
}


#pragma endregion

#define ENUM_CASE_STRING(s) \
case s: \
	return #s;

const char* stringifyGhostType(SGhostType ghostType) {
	using enum SGhostType;

	switch (ghostType) {
		ENUM_CASE_STRING(spirit);
		ENUM_CASE_STRING(wraith);
		ENUM_CASE_STRING(phantom);
		ENUM_CASE_STRING(poltergeist);
		ENUM_CASE_STRING(banshee);
		ENUM_CASE_STRING(jinn);
		ENUM_CASE_STRING(mare);
		ENUM_CASE_STRING(revenant);
		ENUM_CASE_STRING(shade);
		ENUM_CASE_STRING(demon);
		ENUM_CASE_STRING(yurei);
		ENUM_CASE_STRING(oni);
		ENUM_CASE_STRING(yokai);
		ENUM_CASE_STRING(hantu);
		ENUM_CASE_STRING(goryo);
		ENUM_CASE_STRING(myling);
		ENUM_CASE_STRING(onryo);

		case theTwins:
			return "the twins";

		ENUM_CASE_STRING(raiju);
		ENUM_CASE_STRING(obake);
		ENUM_CASE_STRING(mimic);
		ENUM_CASE_STRING(moroi);
		ENUM_CASE_STRING(deogen);
		ENUM_CASE_STRING(thaye);
	}

	return "unknown";
}

const char* stringifyEvidenceType(SGhostEvidenceType evidenceType) {
	using enum SGhostEvidenceType;

	switch (evidenceType) {
		ENUM_CASE_STRING(none);
		ENUM_CASE_STRING(emf);

		case spiritBox:
			return "spirit box";

		ENUM_CASE_STRING(fingerprints);
		
		case ghostOrb:
			return "ghost orb";
		
		case ghostWriting:
			return "ghost writing";

		ENUM_CASE_STRING(freezing);
		ENUM_CASE_STRING(dots);
	}

	return "unknown";
}

#undef ENUM_CASE_STRING

void drawInfo() {
	using namespace Settings::Info;

	{
		using namespace Ghost;

		{
			using namespace Show;

			bool ghostInfoOpened = type || evidence || name || age || gender || deathLength || shyness || favouriteRoom;
			if (ghostInfoOpened) {
				bool oldGhostInfoOpened = ghostInfoOpened;
				if (ImGui::Begin("ghost info", &ghostInfoOpened, ImGuiWindowFlags_AlwaysAutoResize)) {
						if (SGhostAI::instance) {
							SGhostInfo* ghostInfo = SGhostAI::instance->getGhostInfo();
							SGhostTraits ghostTraits = ghostInfo->getGhostTraits();


							if (type) {
								SGhostType ghostType = ghostTraits.getType();
								ImGui::Text("type: %s", stringifyGhostType(ghostType));

								if (ghostType == SGhostType::mimic)
									ImGui::Text("mimic type: %s", stringifyGhostType(ghostTraits.getMimicType()));
							}

							if (evidence) {
								std::stringstream evidenceText;
								evidenceText << "evidence: ";

								int evidenceCount = 0;
								SGhostEvidenceType* evidences = ghostTraits.getEvidences(&evidenceCount);
								if (evidenceCount && evidences) {
									for (int i = 0; i < evidenceCount; i++) {
										if (i)
											evidenceText << " | ";

										evidenceText << stringifyEvidenceType(evidences[i]);
									}
								}
								else
									evidenceText << "none";

								ImGui::Text(evidenceText.str().c_str());


							}

							if (name) {
								if (ghostTraits.getName()) { // Check if getName() returns a valid pointer
									SString* nameManagedString = ghostTraits.getName();
									std::string nameString = nameManagedString ? nameManagedString->toString() : "";
									if (nameString.empty())
										nameString = "???";

									ImGui::Text("Name: %s", nameString.c_str());
								}
								else {
									ImGui::Text("Name: [Unavailable]");
								}
							}
								
							if (age)
									ImGui::Text("age: %d", ghostTraits.getAge());

								if (gender)
									ImGui::Text("gender: %s", ghostTraits.isMale() ? "male" : "female");

								if (deathLength)
									ImGui::Text("death length: %d", ghostTraits.getDeathLength());

								if (shyness)
									ImGui::Text("is shy: %s", ghostTraits.isShy() ? "yes" : "no");

								if (favouriteRoom) {
									if (ghostInfo && ghostInfo->getFavouriteRoom() && ghostInfo->getFavouriteRoom()->getName()) {
										ImGui::Text("Favourite room: %s", ghostInfo->getFavouriteRoom()->getName()->toString().c_str());
									}
									else {
										ImGui::Text("Favourite room: [Unavailable]");
									}
								}
							}
							else
								ImGui::Text("waiting for game...");
						}


			

					

						
				

					
				ImGui::End();
				if (!ghostInfoOpened && oldGhostInfoOpened) {
					type = false;
					evidence = false;

					name = false;
					age = false;
					gender = false;
					deathLength = false;

					shyness = false;
					favouriteRoom = false;
				}
			}
		}

		{
			using namespace Activity;
			using namespace Activity::Show;

			bool ghostActivityOpened = hunting || strength || graph;
			if (ghostActivityOpened) {
				bool oldGhostActivityOpened = ghostActivityOpened;
				if (ImGui::Begin("ghost activity", &ghostActivityOpened, ImGuiWindowFlags_AlwaysAutoResize)) {
					if (SGhostAI::instance) {
						


						if (hunting)
							ImGui::Text("is hunting: %s", SGhostAI::instance->isHunting() ? "yes" : "no");


						if (strength) {
							ImGui::Text("strength: %d", (int) std::floor(graphPoints[0] / 48));

							ImGui::SameLine();
							ImGui::TextDisabled("(?)");
							if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
								ImGui::SetTooltip("calculated by dividing the graph value with 48; a graph value of 480 would be strength 10");
						}

						if (graph)
							ImGui::PlotLines("graph", graphPoints, IM_ARRAYSIZE(graphPoints), 0, nullptr, 0, 480, { 200.0f, 100.0f });
					}
					else
						ImGui::Text("waiting for game...");
				}

				ImGui::End();
				if (!ghostActivityOpened && oldGhostActivityOpened) {
					hunting = false;
					strength = false;
					graph = false;
				}
			}
		}
	}

	{
		using namespace Sanity;

		if (show) {
			if (ImGui::Begin("sanity", &show, ImGuiWindowFlags_AlwaysAutoResize)) {
				if (SGhostAI::instance) {
					//std::vector<SPlayerSpot*> playerSpots = SNetwork::get()->getPlayerSpots();

					std::vector<SPlayerSpot*> playerSpots = SNetwork::get()->getPlayerSpots();

					float sanities = 0.0f;
					for (SPlayerSpot* playerSpot : playerSpots) {
						SPlayer* player = playerSpot->getPlayer();
						if (player)
							sanities += player->getSanity()->getSanity();
					}

					ImGui::Text("average: %.2f%%", sanities / playerSpots.size());
					for (SPlayerSpot* playerSpot : playerSpots) {
						SPhotonPlayer* photonPlayer = playerSpot->getPhotonPlayer();
						SPlayer* player = playerSpot->getPlayer();
						ImGui::Text("%s: %.2f%%%s", photonPlayer->getNickName()->toString().c_str(), player ? player->getSanity()->getSanity() : 0.0f, photonPlayer->isLocal() ? " (you)" : "");
					}
				}
				else
					ImGui::Text("waiting for game...");
			}

			ImGui::End();
		}
	}
}

bool GUI::isInitialized = false;
bool GUI::isUnlocked = false;

void GUI::draw() {
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, isUnlocked ? 0.75f : 0.25f);

	if (isUnlocked)
		drawMainMenu();

	drawInfo();

	ImGui::PopStyleVar();
}
