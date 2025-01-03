#pragma once

class ESP {
public:
	struct LabelData {
		bool enabled;
		SVector3 position;
		std::string text;
		SColor color;

		LabelData() : enabled(false), position(SVector3::zero), text("???"), color(SColor::white) {}
	};

	static void reset();

	static void addEvidence(SEvidence* evidence);

	static void prepareEvidence();

	static void updateAnimator(SAnimator* animator, SColor* color, bool* shouldDraw);

	static void drawLabels();

	static void drawAnimators();

	static LabelData* getLabelData(void* labelId);

	static void removeLabel(void* labelId);

	static void removeEvidence(SEvidence* evidence);

	static void removeAnimator(SAnimator* animator);

private:
	struct AnimatorData {
		SVector3* bonePositions;
		SColor* color;
		bool* shouldDraw;
	};

	static std::map<SAnimator*, AnimatorData> animatorDataMap;
	static std::map<void*, LabelData> labelDataMap;
	static std::set<SEvidence*> evidenceSet;
};
