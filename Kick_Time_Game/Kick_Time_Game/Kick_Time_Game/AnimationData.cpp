#include "AnimationData.h"
#include "ColliderData.h"

const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =
{
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STAND_RIGHT, 0, 0, 75, 138, 4, 7, true, 38, COLLIDER_REPTILE_STAND_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_MOVE_RIGHT_RIGHT, 0, 142, 82, 145, 6, 9, true, 38, COLLIDER_REPTILE_MOVE_RIGHT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_MOVE_LEFT_RIGHT, 0, 297, 73, 143, 6, 8, true, 30, COLLIDER_REPTILE_MOVE_LEFT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCH_RIGHT, 0, 443, 68, 124, 3, 3, false, 26, COLLIDER_REPTILE_CROUCH_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STANDUP_RIGHT, 0, 576, 68, 124, 3, 3, false, 26, COLLIDER_REPTILE_STANDUP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STEADY_JUMP_UP_RIGHT, 0, 709, 77, 148, 6, 3, false, 37, COLLIDER_REPTILE_STEADY_JUMP_UP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STEADY_JUMP_DOWN_RIGHT, 0, 865, 77, 148, 6, 3, false, 37, COLLIDER_REPTILE_STEADY_JUMP_DOWN_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_FORWARD_JUMP_RIGHT, 0, 1019, 67, 146, 4, 8, false, 30, COLLIDER_REPTILE_FORWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_BACKWARD_JUMP_RIGHT, 0, 2719, 67, 146, 4, 8, false, 30, COLLIDER_REPTILE_BACKWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_GUARD_RIGHT, 0, 1166, 67, 140, 1, 3, false, 25, COLLIDER_REPTILE_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_GUARD_ON_RIGHT, 134, 1166, 67, 140, 1, 1, true, 25, COLLIDER_REPTILE_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_GUARD_RIGHT, 0, 1326, 69, 87, 1, 3, false, 25, COLLIDER_REPTILE_LOW_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_GUARD_ON_RIGHT, 138, 1326, 69, 87, 1, 1, true, 25, COLLIDER_REPTILE_LOW_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_PUNCH_RIGHT, 0, 1444, 103, 143, 6, 9, false, 26, COLLIDER_REPTILE_PUNCH_RIGHT, COLLIDER_REPTILE_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_KICK_RIGHT, 0, 1601, 125, 142, 6, 7, false, 36, COLLIDER_REPTILE_KICK_RIGHT, COLLIDER_REPTILE_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_KICK_RIGHT, 0, 1742, 114, 101, 6, 7, false, 28, COLLIDER_REPTILE_CROUCHED_KICK_RIGHT, COLLIDER_REPTILE_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_PUNCH_RIGHT, 0, 1871, 101, 97, 6, 3, false, 33, COLLIDER_REPTILE_CROUCHED_PUNCH_RIGHT, COLLIDER_REPTILE_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_JUMPED_PUNCH_RIGHT, 0, 1981, 148, 88, 6, 3, false, 70, COLLIDER_REPTILE_JUMPED_PUNCH_RIGHT, COLLIDER_REPTILE_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_JUMPED_KICK_RIGHT, 0, 2092, 129, 96, 6, 3, false, 30, COLLIDER_REPTILE_JUMPED_KICK_RIGHT, COLLIDER_REPTILE_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_HIT_RIGHT, 0, 2203, 79, 136, 6, 3, false, 32, COLLIDER_REPTILE_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_HIT_RIGHT, 0, 2348, 75, 94, 6, 3, false, 27, COLLIDER_REPTILE_LOW_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_VICTORY_RIGHT, 0, 2455, 58, 167, 6, 3, false, 23, COLLIDER_REPTILE_VICTORY_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_RIGHT, 0, 2627, 61, 79, 1, 1, true, 26, COLLIDER_REPTILE_CROUCHED_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STAND_LEFT, 1912, 0, -75, 138, 4, 7, true, 35, COLLIDER_REPTILE_STAND_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_MOVE_RIGHT_LEFT, 1912, 297, -73, 143, 6, 8, true, 35, COLLIDER_REPTILE_MOVE_RIGHT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_MOVE_LEFT_LEFT, 1912, 142, -82, 145, 6, 9, true, 52, COLLIDER_REPTILE_MOVE_LEFT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCH_LEFT, 1912, 443, -68, 124, 3, 3, false, 42, COLLIDER_REPTILE_CROUCH_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STANDUP_LEFT, 1912, 576, -68, 124, 3, 3, false, 42, COLLIDER_REPTILE_STANDUP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STEADY_JUMP_UP_LEFT, 1912, 709, -77, 148, 6, 3, false, 40, COLLIDER_REPTILE_STEADY_JUMP_UP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_STEADY_JUMP_DOWN_LEFT, 1912, 865, -77, 148, 6, 3, false, 40, COLLIDER_REPTILE_STEADY_JUMP_DOWN_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_FORWARD_JUMP_LEFT, 1912, 1019, -67, 146, 4, 8, false, 37, COLLIDER_REPTILE_FORWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_BACKWARD_JUMP_LEFT, 1912, 2721, -67, 146, 4, 8, false, 37, COLLIDER_REPTILE_BACKWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_GUARD_LEFT, 1912, 1166, -67, 140, 1, 3, false, 42, COLLIDER_REPTILE_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_GUARD_ON_LEFT, 1776, 1166, -67, 140, 1, 1, true, 42, COLLIDER_REPTILE_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_GUARD_LEFT, 1912, 1326, -69, 97, 1, 3, false, 44, COLLIDER_REPTILE_LOW_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_GUARD_ON_LEFT, 1774, 1326, -69, 97, 1, 1, true, 44, COLLIDER_REPTILE_LOW_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_PUNCH_LEFT, 1912, 1445, -103, 143, 6, 9, false, 77, COLLIDER_REPTILE_PUNCH_LEFT, COLLIDER_REPTILE_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_KICK_LEFT, 1912, 1601, -125, 142, 6, 7, false, 89, COLLIDER_REPTILE_KICK_LEFT, COLLIDER_REPTILE_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_KICK_LEFT, 1912, 1742, -114, 101, 6, 7, false, 86, COLLIDER_REPTILE_CROUCHED_KICK_LEFT, COLLIDER_REPTILE_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_PUNCH_LEFT, 1912, 1871, -101, 97, 6, 3, false, 68, COLLIDER_REPTILE_CROUCHED_PUNCH_LEFT, COLLIDER_REPTILE_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_JUMPED_PUNCH_LEFT, 1912, 1981, -148, 88, 6, 3, false, 78, COLLIDER_REPTILE_JUMPED_PUNCH_LEFT, COLLIDER_REPTILE_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_JUMPED_KICK_LEFT, 1912, 2092, -129, 96, 6, 3, false, 99, COLLIDER_REPTILE_JUMPED_KICK_LEFT, COLLIDER_REPTILE_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_HIT_LEFT, 1912, 2203, -79, 136, 6, 3, false, 47, COLLIDER_REPTILE_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_LOW_HIT_LEFT, 1912, 2348, -75, 94, 6, 3, false, 48, COLLIDER_REPTILE_LOW_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_VICTORY_LEFT, 1912, 2455, -58, 167, 6, 3, false, 35, COLLIDER_REPTILE_VICTORY_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Reptile/Reptile.png", REPTILE_CROUCHED_LEFT, 1912, 2627, -61, 79, 1, 1, true, 35, COLLIDER_REPTILE_CROUCHED_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STAND_RIGHT, 0, 0, 75, 138, 4, 7, true, 38, COLLIDER_SCORPION_STAND_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_MOVE_RIGHT_RIGHT, 0, 142, 82, 145, 6, 9, true, 38, COLLIDER_SCORPION_MOVE_RIGHT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_MOVE_LEFT_RIGHT, 0, 297, 73, 143, 6, 8, true, 30, COLLIDER_SCORPION_MOVE_LEFT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCH_RIGHT, 0, 443, 68, 124, 3, 3, false, 26, COLLIDER_SCORPION_CROUCH_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STANDUP_RIGHT, 0, 576, 68, 124, 3, 3, false, 26, COLLIDER_SCORPION_STANDUP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_UP_RIGHT, 0, 709, 77, 148, 6, 3, false, 37, COLLIDER_SCORPION_STEADY_JUMP_UP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_DOWN_RIGHT, 0, 865, 77, 148, 6, 3, false, 37, COLLIDER_SCORPION_STEADY_JUMP_DOWN_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_JUMP_RIGHT, 0, 1019, 67, 146, 4, 8, false, 30, COLLIDER_SCORPION_FORWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_BACKWARD_JUMP_RIGHT, 0, 2719, 67, 146, 4, 8, false, 30, COLLIDER_SCORPION_BACKWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_RIGHT, 0, 1166, 67, 140, 1, 3, false, 25, COLLIDER_SCORPION_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_ON_RIGHT, 134, 1166, 67, 140, 1, 1, true, 25, COLLIDER_SCORPION_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_RIGHT, 0, 1326, 69, 87, 1, 3, false, 25, COLLIDER_SCORPION_LOW_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_ON_RIGHT, 138, 1326, 69, 87, 1, 1, true, 25, COLLIDER_SCORPION_LOW_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_PUNCH_RIGHT, 0, 1444, 103, 143, 6, 9, false, 26, COLLIDER_SCORPION_PUNCH_RIGHT, COLLIDER_SCORPION_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_KICK_RIGHT, 0, 1601, 125, 142, 6, 7, false, 36, COLLIDER_SCORPION_KICK_RIGHT, COLLIDER_SCORPION_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_KICK_RIGHT, 0, 1742, 114, 101, 6, 7, false, 28, COLLIDER_SCORPION_CROUCHED_KICK_RIGHT, COLLIDER_SCORPION_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_PUNCH_RIGHT, 0, 1871, 101, 97, 6, 3, false, 33, COLLIDER_SCORPION_CROUCHED_PUNCH_RIGHT, COLLIDER_SCORPION_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_PUNCH_RIGHT, 0, 1981, 148, 88, 6, 3, false, 70, COLLIDER_SCORPION_JUMPED_PUNCH_RIGHT, COLLIDER_SCORPION_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_KICK_RIGHT, 0, 2092, 129, 96, 6, 3, false, 30, COLLIDER_SCORPION_JUMPED_KICK_RIGHT, COLLIDER_SCORPION_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_HIT_RIGHT, 0, 2203, 79, 136, 6, 3, false, 32, COLLIDER_SCORPION_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_HIT_RIGHT, 0, 2348, 75, 94, 6, 3, false, 27, COLLIDER_SCORPION_LOW_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_VICTORY_RIGHT, 0, 2455, 58, 167, 6, 3, false, 23, COLLIDER_SCORPION_VICTORY_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_RIGHT, 0, 2627, 61, 79, 1, 1, true, 26, COLLIDER_SCORPION_CROUCHED_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STAND_LEFT, 1912, 0, -75, 138, 4, 7, true, 35, COLLIDER_SCORPION_STAND_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_MOVE_RIGHT_LEFT, 1912, 297, -73, 143, 6, 8, true, 35, COLLIDER_SCORPION_MOVE_RIGHT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_MOVE_LEFT_LEFT, 1912, 142, -82, 145, 6, 9, true, 52, COLLIDER_SCORPION_MOVE_LEFT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCH_LEFT, 1912, 443, -68, 124, 3, 3, false, 42, COLLIDER_SCORPION_CROUCH_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STANDUP_LEFT, 1912, 576, -68, 124, 3, 3, false, 42, COLLIDER_SCORPION_STANDUP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_UP_LEFT, 1912, 709, -77, 148, 6, 3, false, 40, COLLIDER_SCORPION_STEADY_JUMP_UP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_DOWN_LEFT, 1912, 865, -77, 148, 6, 3, false, 40, COLLIDER_SCORPION_STEADY_JUMP_DOWN_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_JUMP_LEFT, 1912, 1019, -67, 146, 4, 8, false, 37, COLLIDER_SCORPION_FORWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_BACKWARD_JUMP_LEFT, 1912, 2721, -67, 146, 4, 8, false, 37, COLLIDER_SCORPION_BACKWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_LEFT, 1912, 1166, -67, 140, 1, 3, false, 42, COLLIDER_SCORPION_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_ON_LEFT, 1776, 1166, -67, 140, 1, 1, true, 42, COLLIDER_SCORPION_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_LEFT, 1912, 1326, -69, 97, 1, 3, false, 44, COLLIDER_SCORPION_LOW_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_ON_LEFT, 1774, 1326, -69, 97, 1, 1, true, 44, COLLIDER_SCORPION_LOW_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_PUNCH_LEFT, 1912, 1445, -103, 143, 6, 9, false, 77, COLLIDER_SCORPION_PUNCH_LEFT, COLLIDER_SCORPION_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_KICK_LEFT, 1912, 1601, -125, 142, 6, 7, false, 89, COLLIDER_SCORPION_KICK_LEFT, COLLIDER_SCORPION_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_KICK_LEFT, 1912, 1742, -114, 101, 6, 7, false, 86, COLLIDER_SCORPION_CROUCHED_KICK_LEFT, COLLIDER_SCORPION_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_PUNCH_LEFT, 1912, 1871, -101, 97, 6, 3, false, 68, COLLIDER_SCORPION_CROUCHED_PUNCH_LEFT, COLLIDER_SCORPION_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_PUNCH_LEFT, 1912, 1981, -148, 88, 6, 3, false, 78, COLLIDER_SCORPION_JUMPED_PUNCH_LEFT, COLLIDER_SCORPION_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_KICK_LEFT, 1912, 2092, -129, 96, 6, 3, false, 99, COLLIDER_SCORPION_JUMPED_KICK_LEFT, COLLIDER_SCORPION_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_HIT_LEFT, 1912, 2203, -79, 136, 6, 3, false, 47, COLLIDER_SCORPION_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_HIT_LEFT, 1912, 2348, -75, 94, 6, 3, false, 48, COLLIDER_SCORPION_LOW_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_VICTORY_LEFT, 1912, 2455, -58, 167, 6, 3, false, 35, COLLIDER_SCORPION_VICTORY_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_LEFT, 1912, 2627, -61, 79, 1, 1, true, 35, COLLIDER_SCORPION_CROUCHED_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STAND_RIGHT, 0, 0, 75, 138, 4, 7, true, 38, COLLIDER_SUBZERO_STAND_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_MOVE_RIGHT_RIGHT, 0, 142, 82, 145, 6, 9, true, 38, COLLIDER_SUBZERO_MOVE_RIGHT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_MOVE_LEFT_RIGHT, 0, 297, 73, 143, 6, 8, true, 30, COLLIDER_SUBZERO_MOVE_LEFT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCH_RIGHT, 0, 443, 68, 124, 3, 3, false, 26, COLLIDER_SUBZERO_CROUCH_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STANDUP_RIGHT, 0, 576, 68, 124, 3, 3, false, 26, COLLIDER_SUBZERO_STANDUP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STEADY_JUMP_UP_RIGHT, 0, 709, 77, 148, 6, 3, false, 37, COLLIDER_SUBZERO_STEADY_JUMP_UP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STEADY_JUMP_DOWN_RIGHT, 0, 865, 77, 148, 6, 3, false, 37, COLLIDER_SUBZERO_STEADY_JUMP_DOWN_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_FORWARD_JUMP_RIGHT, 0, 1019, 67, 146, 4, 8, false, 30, COLLIDER_SUBZERO_FORWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_BACKWARD_JUMP_RIGHT, 0, 2719, 67, 146, 4, 8, false, 30, COLLIDER_SUBZERO_BACKWARD_JUMP_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_GUARD_RIGHT, 0, 1166, 67, 140, 1, 3, false, 25, COLLIDER_SUBZERO_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_GUARD_ON_RIGHT, 134, 1166, 67, 140, 1, 1, true, 25, COLLIDER_SUBZERO_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_GUARD_RIGHT, 0, 1326, 69, 87, 1, 3, false, 25, COLLIDER_SUBZERO_LOW_GUARD_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_GUARD_ON_RIGHT, 138, 1326, 69, 87, 1, 1, true, 25, COLLIDER_SUBZERO_LOW_GUARD_ON_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_PUNCH_RIGHT, 0, 1444, 103, 143, 6, 9, false, 26, COLLIDER_SUBZERO_PUNCH_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_KICK_RIGHT, 0, 1601, 125, 142, 6, 7, false, 36, COLLIDER_SUBZERO_KICK_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_KICK_RIGHT, 0, 1742, 114, 101, 6, 7, false, 28, COLLIDER_SUBZERO_CROUCHED_KICK_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_PUNCH_RIGHT, 0, 1871, 101, 97, 6, 3, false, 33, COLLIDER_SUBZERO_CROUCHED_PUNCH_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_JUMPED_PUNCH_RIGHT, 0, 1981, 148, 88, 6, 3, false, 70, COLLIDER_SUBZERO_JUMPED_PUNCH_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_JUMPED_KICK_RIGHT, 0, 2092, 129, 96, 6, 3, false, 30, COLLIDER_SUBZERO_JUMPED_KICK_RIGHT, COLLIDER_SUBZERO_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_HIT_RIGHT, 0, 2203, 79, 136, 6, 3, false, 32, COLLIDER_SUBZERO_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_HIT_RIGHT, 0, 2348, 75, 94, 6, 3, false, 27, COLLIDER_SUBZERO_LOW_HIT_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_VICTORY_RIGHT, 0, 2455, 58, 167, 6, 3, false, 23, COLLIDER_SUBZERO_VICTORY_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_RIGHT, 0, 2627, 61, 79, 1, 1, true, 26, COLLIDER_SUBZERO_CROUCHED_RIGHT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STAND_LEFT, 1912, 0, -75, 138, 4, 7, true, 35, COLLIDER_SUBZERO_STAND_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_MOVE_RIGHT_LEFT, 1912, 297, -73, 143, 6, 8, true, 35, COLLIDER_SUBZERO_MOVE_RIGHT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_MOVE_LEFT_LEFT, 1912, 142, -82, 145, 6, 9, true, 52, COLLIDER_SUBZERO_MOVE_LEFT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCH_LEFT, 1912, 443, -68, 124, 3, 3, false, 42, COLLIDER_SUBZERO_CROUCH_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STANDUP_LEFT, 1912, 576, -68, 124, 3, 3, false, 42, COLLIDER_SUBZERO_STANDUP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STEADY_JUMP_UP_LEFT, 1912, 709, -77, 148, 6, 3, false, 40, COLLIDER_SUBZERO_STEADY_JUMP_UP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_STEADY_JUMP_DOWN_LEFT, 1912, 865, -77, 148, 6, 3, false, 40, COLLIDER_SUBZERO_STEADY_JUMP_DOWN_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_FORWARD_JUMP_LEFT, 1912, 1019, -67, 146, 4, 8, false, 37, COLLIDER_SUBZERO_FORWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_BACKWARD_JUMP_LEFT, 1912, 2721, -67, 146, 4, 8, false, 37, COLLIDER_SUBZERO_BACKWARD_JUMP_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_GUARD_LEFT, 1912, 1166, -67, 140, 1, 3, false, 42, COLLIDER_SUBZERO_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_GUARD_ON_LEFT, 1776, 1166, -67, 140, 1, 1, true, 42, COLLIDER_SUBZERO_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_GUARD_LEFT, 1912, 1326, -69, 97, 1, 3, false, 44, COLLIDER_SUBZERO_LOW_GUARD_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_GUARD_ON_LEFT, 1774, 1326, -69, 97, 1, 1, true, 44, COLLIDER_SUBZERO_LOW_GUARD_ON_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_PUNCH_LEFT, 1912, 1445, -103, 143, 6, 9, false, 77, COLLIDER_SUBZERO_PUNCH_LEFT, COLLIDER_SUBZERO_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_KICK_LEFT, 1912, 1601, -125, 142, 6, 7, false, 89, COLLIDER_SUBZERO_KICK_LEFT, COLLIDER_SUBZERO_KICK_PUNCH),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_KICK_LEFT, 1912, 1742, -114, 101, 6, 7, false, 86, COLLIDER_SUBZERO_CROUCHED_KICK_LEFT, COLLIDER_SUBZERO_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_PUNCH_LEFT, 1912, 1871, -101, 97, 6, 3, false, 68, COLLIDER_SUBZERO_CROUCHED_PUNCH_LEFT, COLLIDER_SUBZERO_KICK_PUNCH_DOWN),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_JUMPED_PUNCH_LEFT, 1912, 1981, -148, 88, 6, 3, false, 78, COLLIDER_SUBZERO_JUMPED_PUNCH_LEFT, COLLIDER_SUBZERO_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_JUMPED_KICK_LEFT, 1912, 2092, -129, 96, 6, 3, false, 99, COLLIDER_SUBZERO_JUMPED_KICK_LEFT, COLLIDER_SUBZERO_KICK_PUNCH_UP),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_HIT_LEFT, 1912, 2203, -79, 136, 6, 3, false, 47, COLLIDER_SUBZERO_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_LOW_HIT_LEFT, 1912, 2348, -75, 94, 6, 3, false, 48, COLLIDER_SUBZERO_LOW_HIT_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_VICTORY_LEFT, 1912, 2455, -58, 167, 6, 3, false, 35, COLLIDER_SUBZERO_VICTORY_LEFT, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Subzero/Subzero.png", SUBZERO_CROUCHED_LEFT, 1912, 2627, -61, 79, 1, 1, true, 35, COLLIDER_SUBZERO_CROUCHED_LEFT, COLLIDER_NULL),
};

AnimationData::AnimationData()
{
	this->fileName = "";
	this->animationName = 0;
	this->posX = 0;
	this->posY = 0;
	this->spriteWidth = 0;
	this->spriteHeight = 0;
	this->framerate = 0;
	this->spriteNb = 0;
	this->animationLoop = false;
	this->shiftPositionXCharacter = 0;
	this->colliderID = COLLIDER_NULL;
	this->colliderKickPunchID = COLLIDER_NULL;
}

AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int shiftPositionXCharacter, int colliderID, int colliderKickPunchID)
{
	this->fileName = fileName;
	this->animationName = animationName;
	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
	this->shiftPositionXCharacter = shiftPositionXCharacter;
	this->colliderID = colliderID;
	this->colliderKickPunchID = colliderKickPunchID;
}

AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop)
{
	this->fileName = fileName;
	this->animationName = animationName;
	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
	this->shiftPositionXCharacter = 0;
	this->colliderID = COLLIDER_NULL;
	this->colliderKickPunchID = COLLIDER_NULL;
}

AnimationData::~AnimationData(void)
{
}

string AnimationData::getFileName() const
{
	return this->fileName;
}

int AnimationData::getAnimationName() const
{
	return this->animationName;
}

int AnimationData::getPosX() const
{
	return this->posX;
}

int AnimationData::getPosY() const
{
	return this->posY;
}

int AnimationData::getSpriteWidth() const
{
	return this->spriteWidth;
}

int AnimationData::getSpriteHeight() const
{
	return this->spriteHeight;
}

int AnimationData::getFramerate() const
{
	return this->framerate;
}

int AnimationData::getSpriteNb() const
{
	return this->spriteNb;
}

bool AnimationData::getAnimationLoop() const
{
	return this->animationLoop;
}

int AnimationData::getShiftPositionXCharacter() const
{
	return this->shiftPositionXCharacter;
}

int AnimationData::getColliderID() const
{
	return this->colliderID;
}

int AnimationData::getColliderKickPunchID() const
{
	return this->colliderKickPunchID;
}
