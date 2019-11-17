#include "Player.h"
void MoveInDirection(Player player, PlayerDirection direction) {
	switch (direction) { 
		case UP:
            if (player.position.y > Player::kMoveSpeed) {
			    player.position.y -= Player::kMoveSpeed;
            }
            break;
        case DOWN:
            if (player.position.y < 
			    (int) ofGetWindowHeight - Player::kPlayerHeight) {
				player.position.y += Player::kMoveSpeed;
            }
            break;
        case LEFT:
            if (player.position.x > Player::kMoveSpeed) {
                player.position.x -= Player::kMoveSpeed;
            }
            break;
        case RIGHT:
            if (player.position.x <
                (int) ofGetWindowWidth - Player::kPlayerWidth) {
                player.position.x += Player::kMoveSpeed;
            }
            break;
	}
}
