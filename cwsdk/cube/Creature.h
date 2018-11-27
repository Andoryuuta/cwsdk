#pragma once

#include <string>

#include "../Vector3.h"
#include "../non_cube.h"

namespace cube {
	struct Creature
	{
		enum class Race
		{
			ElfMale = 0,
			ElfFemale = 1,
			HumanMale = 2,
			HumanFemale = 3,
			GoblinMale = 4,
			GoblinFemale = 5,
			Bullterrier = 6,
			LizardmanMale = 7,
			LizardmanFemale = 8,
			DwarfMale = 9,
			DwarfFemale = 10,
			OrcMale = 11,
			OrcFemale = 12,
			FrogmanMale = 13,
			FrogmanFemale = 14,
			UndeadMale = 15,
			UndeadFemale = 16,
			Skeleton = 17,
			OldMan = 18,
			Collie = 19,
			ShepherdDog = 20,
			SkullBull = 21,
			Alpaca = 22,
			BrownAlpaca = 23,
			Egg = 24,
			Turtle = 25,
			Terrier = 26,
			ScottishTerrier = 27,
			Wolf = 28,
			Panther = 29,
			Cat = 30,
			BrownCat = 31,
			WhiteCat = 32,
			Pig = 33,
			Sheep = 34,
			Bunny = 35,
			Porcupine = 36,
			GreenSlime = 37,
			PinkSlime = 38,
			YellowSlime = 39,
			BlueSlime = 40,
			Frightener = 41,
			SandHorror = 42,
			Wizard = 43,
			Bandit = 44,
			Witch = 45,
			Ogre = 46,
			Rockling = 47,
			Gnoll = 48,
			PolarGnoll = 49,
			Monkey = 50,
			Gnobold = 51,
			Insectoid = 52,
			Hornet = 53,
			InsectGuard = 54,
			Crow = 55,
			Chicken = 56,
			Seagull = 57,
			Parrot = 58,
			Bat = 59,
			Fly = 60,
			Midge = 61,
			Mosquito = 62,
			PlainRunner = 63,
			LeafRunner = 64,
			SnowRunner = 65,
			DesertRunner = 66,
			Peacock = 67,
			Frog = 68,
			PlantCreature = 69,
			RadishCreature = 70,
			Onionling = 71,
			DesertOnionling = 72,
			Devourer = 73,
			Duckbill = 74,
			Crocodile = 75,
			SpikeCreature = 76,
			Anubis = 77,
			Horus = 78,
			Jester = 79,
			Spectrino = 80,
			Djinn = 81,
			Minotaur = 82,
			NomadMale = 83,
			NomadFemale = 84,
			Imp = 85,
			Spitter = 86,
			Mole = 87,
			Biter = 88,
			Koala = 89,
			Squirrel = 90,
			Raccoon = 91,
			Owl = 92,
			Penguin = 93,
			Werewolf = 94,
			Zombie = 96,
			Vampire = 97,
			Horse = 98,
			Camel = 99,
			Cow = 100,
			Dragon = 101,
			BarkBeetle = 102,
			FireBeetle = 103,
			SnoutBeetle = 104,
			LemonBeetle = 105,
			Crab = 106,
			SeaCrab = 107,
			Troll = 108,
			DarkTroll = 109,
			HellDemon = 110,
			Golem = 111,
			EmberGolem = 112,
			SnowGolem = 113,
			Yeti = 114,
			Cyclops = 115,
			Mammoth = 116,
			Lich = 117,
			RuneGiant = 118,
			Saurian = 119,
			Bush = 120,
			SnowBush = 121,
			SnowBerryBush = 122,
			CottonPlant = 123,
			Scrub = 124,
			CobwebScrub = 125,
			FireScrub = 126,
			Ginseng = 127,
			Cactus = 128,
			ThornTree = 130,
			GoldDeposit = 131,
			IronDeposit = 132,
			SilverDeposit = 133,
			SandstoneDeposit = 134,
			EmeraldDeposit = 135,
			SapphireDeposit = 136,
			RubyDeposit = 137,
			DiamondDeposit = 138,
			IceCrystalDeposit = 139,
			Scarecrow = 140,
			Aim = 141,
			Dummy = 142,
			Vase = 143,
			Bomb = 144,
			SapphireFish = 145,
			LemonFish = 146,
			Seahorse = 147,
			Mermaid = 148,
			Merman = 149,
			Shark = 150,
			Bumblebee = 151,
			LanternFish = 152,
			MawFish = 153,
			Piranha = 154,
			Blowfish = 155,
		};


		int vftable;
		int field_4;
		int64_t GUID;

		struct {
			Vector3<int64_t> position;
			Vector3<float> rotation;
			Vector3<float> velocity;
			Vector3<float> acceleration;
			Vector3<float> retreat_force;
			int head_rotation;
			uint8_t physics_flags;
			uint8_t field_4D;
			char field_4E;
			char field_4F;
			uint8_t hostility_flags;
			uint32_t race;
			uint8_t skill_id;
			int skill_timer;
			int hit_counter;
			int time_since_last_hit;
			struct {
				char appearance_struct_field_0;
				char field_1;
				uint8_t hair_color_red;
				uint8_t hair_color_green;
				uint8_t hair_color_blue;
				char field_5;
				uint16_t movement_flags;
				float graphical_size;
				float hitbox_size;
				float physical_size;
				uint16_t face_id;
				uint16_t hair_id;
				uint16_t hands_id;
				uint16_t feet_id;
				uint16_t chest_id;
				uint16_t tail_id;
				uint16_t shoulder_id;
				uint16_t wings_id;
				float head_scale;
				float chest_scale;
				float hand_scale;
				float feet_scale;
				float unk_scale;
				float weapon_scale;
				float tail_scale;
				float shoulder_scale;
				float wings_scale;
				int chest_rotation;
				Vector3<float> hands_rotation;
				int feet_rotation;
				int wings_rotation;
				int unk_rotation;
				Vector3<float> chest_position;
				Vector3<float> head_position;
				Vector3<float> hands_position;
				Vector3<float> feet_position;
				Vector3<float> unk_position;
				Vector3<float> wings_position;
			} appearance;

			// 0x0010 = Glider
			// 0x0200 = Light
			uint16_t binary_toggles;
			uint16_t field_116;
			int rolling_duration;
			float stun_timer;
			int unknown_effect;
			int ice_spirit_effect;
			int wind_spirit_effect;
			int show_patch_time;
			char char_class;
			char char_specialization;
			char field_132;
			char field_133;
			int special_hit_power_or_charge;
			int field_138;
			int field_13C;
			int field_140;
			int field_144;
			int field_148;
			float field_14C;
			Vector3<float> camera_offset;
			float hp;
			float mp;
			float block_power;
			float hp_multiplier;
			int attack_speed_multiplier;
			int damage_multiplier;
			int armor_multiplier;
			int resistance_multiplier;
			int unk_multiplier;
			int level;
			int experience;
			int64_t parent_owner;
			int field_190;
			int field_194;
			int power_base;
			int field_19C;
			int field_1A0;
			int field_1A4;
			int field_1A8;
			int field_1AC;
			int field_1B0;
			int field_1B4;
			int field_1B8;
			int field_1BC;
			int field_1C0;
			int field_1C4;
			int field_1C8;
			int field_1CC;
			int field_1D0;
			int field_1D4;
			int field_1D8;
			int field_1DC;
			int field_1E0;
			int field_1E4;
			int field_1E8;
			char some_buf[256];
			int field_2EC;
			WornEquipment equipment;
			int skill_level_petmaster;
			int skill_level_riding;
			int skill_level_climbing;
			int skill_level_gliding;
			int skill_level_swimming;
			int skill_level_sailing;
			int skill_level_class_1;
			int skill_level_class_2;
			int skill_level_class_3;
			int skill_level_class_4;
			int skill_level_class_5;
			int field_1154;
			/*
			int64_t field_1158;
			int64_t field_1160;
			*/
			char name[16];
		} entity_data;

		int field_1178;
		int field_117C;
		int field_1180;
		int field_1184;
		int field_1188;
		int field_118C;
		int field_1190;
		float stamina;
		int field_1198;
		int field_119C;
		int field_11A0;
		int field_11A4;
		int field_11A8;
		void *field_11AC_map;
		int field_11B0;
		void *field_11B4_map;
		int field_11B8;
		int field_11BC;
		int field_11C0;
		int field_11C4;
		int field_11C8;
		int field_11CC;
		int field_11D0;
		int field_11D4;
		int field_11D8;
		STDVector Inventory_Tabs_Vec;
		int field_11E8;
		int field_11EC;
		int field_11F0;
		int field_11F4;
		int field_11F8;
		int field_11FC;
		int field_1200;
		int field_1204;
		int field_1208;
		int field_120C;
		int field_1210;
		int field_1214;
		int field_1218;
		int field_121C;
		int field_1220;
		int field_1224;
		int field_1228;
		int field_122C;
		int field_1230;
		int field_1234;
		int field_1238;
		int field_123C;
		int field_1240;
		int field_1244;
		int field_1248;
		int field_124C;
		int field_1250;
		int field_1254;
		int field_1258;
		int field_125C;
		int field_1260;
		int field_1264;
		int field_1268;
		int field_126C;
		int field_1270;
		int field_1274;
		int field_1278;
		int field_127C;
		int field_1280;
		int field_1284;
		int field_1288;
		int field_128C;
		int field_1290;
		int field_1294;
		int field_1298;
		int field_129C;
		int field_12A0;
		int field_12A4;
		int field_12A8;
		int field_12AC;
		int field_12B0;
		int field_12B4;
		int field_12B8;
		int field_12BC;
		int field_12C0;
		int field_12C4;
		int field_12C8;
		int field_12CC;
		int field_12D0;
		int field_12D4;
		int field_12D8;
		int field_12DC;
		int field_12E0;
		int field_12E4;
		int field_12E8;
		int field_12EC;
		int field_12F0;
		int field_12F4;
		int field_12F8;
		int field_12FC;
		int money;
		int platinum_coins;
		char other_stuff[2900];
		int field_1E5C;


		std::wstring GetName();
		double DistanceFrom(Vector3<int64_t> point);
		double DistanceFrom(Creature*);

	};
};