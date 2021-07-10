#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
	public:
		unsigned int startFrame;
		unsigned int endFrame;
		float duration;

		Animation(unsigned int startFrame, unsigned int endFrame, float duration) {
			this->startFrame = startFrame;
			this->endFrame = endFrame;
			this->duration = duration;
		}
		unsigned int getLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler {
	private:
		std::vector<Animation> animations;
		float t;
		int currentAnim;
	
	public:
		sf::IntRect bounds;
		sf::IntRect frameSize;

		void addAnim(Animation &anim);
		void update(const float dt);
		void changeAnim(unsigned int animNum);
		AnimationHandler() {
			this->t = 0.0f;
			this->currentAnim = -1;
		}
		AnimationHandler(const sf::IntRect &frameSize) {
			this->frameSize = frameSize;
			this->t = 0.0f;
			this->currentAnim = -1;
		}
};

#endif