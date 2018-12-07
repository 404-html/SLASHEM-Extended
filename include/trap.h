/*	SCCS Id: @(#)trap.h	3.4	2000/08/30	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

/* note for 3.1.0 and later: no longer manipulated by 'makedefs' */

#ifndef TRAP_H
#define TRAP_H

union vlaunchinfo {
	short v_launch_otyp;	/* type of object to be triggered */
	coord v_launch2;	/* secondary launch point (for boulders) */
};

struct trap {
	struct trap *ntrap;
	xchar tx,ty;
	d_level dst;	/* destination for portals */
	coord launch;
	int ttyp; /* are you kidding me? You only make room for 32 traps? That's not nearly enough for me! --Amy */
	int trapdiff; /* difficulty - this affects your chance of finding it via search command */
	Bitfield(tseen,1);
	Bitfield(hiddentrap,1); /* invisible, and I mean really invisible, even if you have see invis --Amy */
	Bitfield(once,1);
	Bitfield(tdetected,1); /* so things like map amnesia don't allow you to farm searching skill --Amy */
	Bitfield(madeby_u,1); /* So monsters may take offence when you trap
				 them.	Recognizing who made the trap isn't
				 completely unreasonable, everybody has
				 their own style.  This flag is also needed
				 when you untrap a monster.  It would be too
				 easy to make a monster peaceful if you could
				 set a trap for it and then untrap it. */
	union vlaunchinfo vl;
#define launch_otyp	vl.v_launch_otyp
#define launch2		vl.v_launch2
};

extern struct trap *ftrap;
#define newtrap()	(struct trap *) alloc(sizeof(struct trap))
#define dealloc_trap(trap) free((void *) (trap))

/* reasons for statue animation */
#define ANIMATE_NORMAL	0
#define ANIMATE_SHATTER 1
#define ANIMATE_SPELL	2

/* reasons for animate_statue's failure */
#define AS_OK		 0	/* didn't fail */
#define AS_NO_MON	 1	/* makemon failed */
#define AS_MON_IS_UNIQUE 2	/* statue monster is unique */

/* Note: if adding/removing a trap, adjust trap_engravings[] in mklev.c */

/* unconditional traps */
#define NO_TRAP		0
#define ARROW_TRAP	1
#define DART_TRAP	2
#define ROCKTRAP	3
#define SQKY_BOARD	4
#define BEAR_TRAP	5
#define LANDMINE	6
#define ROLLING_BOULDER_TRAP	7
#define SLP_GAS_TRAP	8
#define RUST_TRAP	9
#define FIRE_TRAP	10
#define PIT		11
#define SPIKED_PIT	12
#define HOLE		13
#define TRAPDOOR	14
#define TELEP_TRAP	15
#define LEVEL_TELEP	16
#define MAGIC_PORTAL	17
#define WEB		18
#define STATUE_TRAP	19
#define MAGIC_TRAP	20
#define ANTI_MAGIC	21
#define POLY_TRAP	22
#define ICE_TRAP	23
#define SPEAR_TRAP	24
#define COLLAPSE_TRAP	25
#define MAGIC_BEAM_TRAP	26
#define SHIT_TRAP	27
#define ANIMATION_TRAP	28
#define GLYPH_OF_WARDING	29
#define SCYTHING_BLADE	30
#define BOLT_TRAP	31
#define ACID_POOL	32
#define WATER_POOL	33
#define POISON_GAS_TRAP	34
#define SLOW_GAS_TRAP	35
#define SHOCK_TRAP	36
#define RMB_LOSS_TRAP		37
#define DISPLAY_TRAP		38
#define SPELL_LOSS_TRAP		39
#define YELLOW_SPELL_TRAP		40
#define AUTO_DESTRUCT_TRAP		41
#define MEMORY_TRAP		42
#define INVENTORY_TRAP		43
#define BLACK_NG_WALL_TRAP		44
#define MENU_TRAP		45
#define SPEED_TRAP		46
#define SUPERSCROLLER_TRAP		47
#define ACTIVE_SUPERSCROLLER_TRAP		48
#define SWARM_TRAP		49
#define AUTOMATIC_SWITCHER		50
#define UNKNOWN_TRAP		51
#define HEEL_TRAP		52
#define VULN_TRAP		53
#define LAVA_TRAP		54
#define FLOOD_TRAP		55
#define DRAIN_TRAP		56
#define FREE_HAND_TRAP		57
#define DISINTEGRATION_TRAP		58
#define UNIDENTIFY_TRAP		59
#define THIRST_TRAP		60
#define LUCK_TRAP		61
#define SHADES_OF_GREY_TRAP		62
#define ITEM_TELEP_TRAP		63
#define GRAVITY_TRAP		64
#define DEATH_TRAP		65
#define STONE_TO_FLESH_TRAP		66
#define QUICKSAND_TRAP		67
#define FAINT_TRAP		68
#define CURSE_TRAP		69
#define DIFFICULTY_TRAP		70
#define SOUND_TRAP		71
#define CASTER_TRAP		72
#define WEAKNESS_TRAP		73
#define ROT_THIRTEEN_TRAP		74
#define BISHOP_TRAP		75
#define CONFUSION_TRAP		76
#define NUPESELL_TRAP		77
#define DROP_TRAP		78
#define DSTW_TRAP		79
#define STATUS_TRAP		80
#define ALIGNMENT_TRAP		81
#define STAIRS_TRAP		82

#define PESTILENCE_TRAP		83
#define FAMINE_TRAP		84
#define RELOCATION_TRAP		85

#define UNINFORMATION_TRAP		86

#define INTRINSIC_LOSS_TRAP	87
#define BLOOD_LOSS_TRAP	88
#define BAD_EFFECT_TRAP	89
#define MULTIPLY_TRAP	90
#define AUTO_VULN_TRAP	91
#define TELE_ITEMS_TRAP	92
#define NASTINESS_TRAP	93

#define RECURSION_TRAP	94
#define RESPAWN_TRAP	95
#define WARP_ZONE	96
#define CAPTCHA_TRAP	97
#define MIND_WIPE_TRAP	98
#define THROWING_STAR_TRAP	99
#define SHIT_PIT	100
#define SHAFT_TRAP	101
#define LOCK_TRAP	102
#define MAGIC_CANCELLATION_TRAP	103
#define FARLOOK_TRAP	104
#define GATEWAY_FROM_HELL	105
#define GROWING_TRAP	106
#define COOLING_TRAP	107
#define BAR_TRAP	108
#define LOCKING_TRAP	109
#define AIR_TRAP	110
#define TERRAIN_TRAP	111

#define LOUDSPEAKER 112
#define NEST_TRAP 113
#define BULLET_TRAP 114
#define PARALYSIS_TRAP 115
#define CYANIDE_TRAP 116
#define LASER_TRAP 117
#define GIANT_CHASM 118
#define FART_TRAP 119
#define CONFUSE_TRAP 120
#define STUN_TRAP 121
#define HALLUCINATION_TRAP 122
#define PETRIFICATION_TRAP 123
#define NUMBNESS_TRAP 124
#define FREEZING_TRAP 125
#define BURNING_TRAP 126
#define FEAR_TRAP 127
#define BLINDNESS_TRAP 128
#define GLIB_TRAP 129
#define SLIME_TRAP 130
#define INERTIA_TRAP 131
#define TIME_TRAP 132
#define LYCANTHROPY_TRAP 133
#define UNLIGHT_TRAP 134
#define ELEMENTAL_TRAP 135
#define ESCALATING_TRAP 136
#define NEGATIVE_TRAP 137
#define MANA_TRAP 138
#define SIN_TRAP 139
#define DESTROY_ARMOR_TRAP 140
#define DIVINE_ANGER_TRAP 141
#define GENETIC_TRAP 142
#define MISSINGNO_TRAP 143
#define CANCELLATION_TRAP 144
#define HOSTILITY_TRAP 145
#define BOSS_TRAP 146
#define WISHING_TRAP 147
#define RECURRING_AMNESIA_TRAP 148
#define BIGSCRIPT_TRAP 149
#define BANK_TRAP 150
#define ONLY_TRAP 151
#define MAP_TRAP 152
#define TECH_TRAP 153
#define DISENCHANT_TRAP 154
#define VERISIERT 155
#define CHAOS_TRAP 156
#define MUTENESS_TRAP 157
#define NTLL_TRAP 158
#define ENGRAVING_TRAP 159
#define MAGIC_DEVICE_TRAP 160
#define BOOK_TRAP 161
#define LEVEL_TRAP 162
#define QUIZ_TRAP 163

#define FALLING_BOULDER_TRAP 164
#define GLASS_ARROW_TRAP 165
#define GLASS_BOLT_TRAP 166
#define OUT_OF_MAGIC_TRAP 167
#define PLASMA_TRAP 168
#define BOMB_TRAP 169
#define EARTHQUAKE_TRAP 170
#define NOISE_TRAP 171
#define GLUE_TRAP 172
#define GUILLOTINE_TRAP 173
#define BISECTION_TRAP 174
#define VOLT_TRAP 175
#define HORDE_TRAP 176
#define IMMOBILITY_TRAP 177
#define GREEN_GLYPH 178
#define BLUE_GLYPH 179
#define YELLOW_GLYPH 180
#define ORANGE_GLYPH 181
#define BLACK_GLYPH 182
#define PURPLE_GLYPH 183

#define METABOLIC_TRAP 184
#define TRAP_OF_NO_RETURN 185
#define EGOTRAP 186
#define FAST_FORWARD_TRAP 187
#define TRAP_OF_ROTTENNESS 188
#define UNSKILLED_TRAP 189
#define LOW_STATS_TRAP 190
#define TRAINING_TRAP 191
#define EXERCISE_TRAP 192
#define FALLING_LOADSTONE_TRAP 193
#define SUMMON_UNDEAD_TRAP 194
#define FALLING_NASTYSTONE_TRAP 195

#define SPINED_BALL_TRAP	196	/*[Sakusha]*/
#define PENDULUM_TRAP	197		/*[Sakusha]*/
#define TURN_TABLE	198		/*[Sakusha]*/
#define SCENT_TRAP	199		/*[Sakusha]*/
#define BANANA_TRAP	200		/*[Sakusha]*/
#define FALLING_TUB_TRAP	201	/*from RJNH*/
#define ALARM		202		/*[Sakusha]*/
#define CALTROPS_TRAP	203		/*[Sakusha]*/
#define BLADE_WIRE	204		/*[Sakusha]*/
#define MAGNET_TRAP	205		/*from RJNH*/
#define SLINGSHOT_TRAP	206		/*[Sakusha]*/
#define CANNON_TRAP	207		/*[Sakusha]*/
#define VENOM_SPRINKLER	208		/*[Sakusha]*/
#define FUMAROLE	209		/*[Sakusha]*/

#define MANA_PIT 210
#define ELEMENTAL_PORTAL 211
#define GIRLINESS_TRAP 212
#define FUMBLING_TRAP 213
#define EGOMONSTER_TRAP 214
#define FLOODING_TRAP 215
#define MONSTER_CUBE 216
#define CURSED_GRAVE 217
#define LIMITATION_TRAP 218
#define WEAK_SIGHT_TRAP 219
#define RANDOM_MESSAGE_TRAP 220

#define DESECRATION_TRAP 221
#define STARVATION_TRAP 222
#define DROPLESS_TRAP 223
#define LOW_EFFECT_TRAP 224
#define INVISIBLE_TRAP 225
#define GHOST_WORLD_TRAP 226
#define DEHYDRATION_TRAP 227
#define HATE_TRAP 228
#define SPACEWARS_TRAP 229
#define TEMPORARY_RECURSION_TRAP 230
#define TOTTER_TRAP 231
#define NONINTRINSICAL_TRAP 232
#define DROPCURSE_TRAP 233
#define NAKEDNESS_TRAP 234
#define ANTILEVEL_TRAP 235
#define VENTILATOR 236
#define STEALER_TRAP 237
#define REBELLION_TRAP 238
#define CRAP_TRAP 239
#define MISFIRE_TRAP 240
#define TRAP_OF_WALLS 241

#define DISCONNECT_TRAP 242
#define INTERFACE_SCREW_TRAP 243
#define DIMNESS_TRAP 244
#define EVIL_ARTIFACT_TRAP 245
#define BOSSFIGHT_TRAP 246
#define ENTIRE_LEVEL_TRAP 247
#define BONES_TRAP 248
#define RODNEY_TRAP 249
#define AUTOCURSE_TRAP 250
#define HIGHLEVEL_TRAP 251
#define SPELL_FORGETTING_TRAP 252
#define SOUND_EFFECT_TRAP 253

#define TRAP_PERCENTS	254

#define NEXUS_TRAP	255
#define LEG_TRAP	256
#define ARTIFACT_JACKPOT_TRAP	257
#define MAP_AMNESIA_TRAP	258
#define SPREADING_TRAP	259
#define ADJACENT_TRAP	260
#define SUPERTHING_TRAP	261
#define CURRENT_SHAFT	262
#define LEVITATION_TRAP	263
#define BOWEL_CRAMPS_TRAP	264
#define UNEQUIPPING_TRAP	265
#define GOOD_ARTIFACT_TRAP	266
#define GENDER_TRAP	267
#define TRAP_OF_OPPOSITE_ALIGNMENT	268
#define SINCOUNT_TRAP	269
#define BEAMER_TRAP	270
#define LEVEL_BEAMER	271
#define PET_TRAP	272
#define PIERCING_BEAM_TRAP	273
#define WRENCHING_TRAP	274
#define TRACKER_TRAP	275
#define NURSE_TRAP	276
#define BACK_TO_START_TRAP	277
#define NEMESIS_TRAP	278
#define STREW_TRAP	279
#define OUTTA_DEPTH_TRAP	280
#define PUNISHMENT_TRAP	281
#define BOON_TRAP	282
#define FOUNTAIN_TRAP	283
#define THRONE_TRAP	284
#define ANOXIC_PIT	285
#define ARABELLA_SPEAKER	286
#define FEMMY_TRAP	287
#define MADELEINE_TRAP	288
#define MARLENA_TRAP	289
#define ANASTASIA_TRAP	290
#define FILLER_TRAP	291
#define TOXIC_VENOM_TRAP	292
#define INSANITY_TRAP	293
#define MADNESS_TRAP	294
#define JESSICA_TRAP	295
#define SOLVEJG_TRAP	296
#define WENDY_TRAP	297
#define KATHARINA_TRAP	298
#define ELENA_TRAP	299
#define THAI_TRAP	300
#define ELIF_TRAP	301
#define NADJA_TRAP	302
#define SANDRA_TRAP	303
#define NATALJE_TRAP	304
#define JEANETTA_TRAP	305
#define YVONNE_TRAP	306
#define MAURAH_TRAP	307

#define LOOTCUT_TRAP	308
#define MONSTER_SPEED_TRAP	309
#define SCALING_TRAP	310
#define ENMITY_TRAP	311
#define WHITE_SPELL_TRAP	312
#define COMPLETE_GRAY_SPELL_TRAP	313
#define QUASAR_TRAP	314
#define MOMMA_TRAP	315
#define HORROR_TRAP	316
#define ARTIFICER_TRAP	317
#define WEREFORM_TRAP	318
#define NON_PRAYER_TRAP	319
#define EVIL_PATCH_TRAP	320
#define HARD_MODE_TRAP	321
#define SECRET_ATTACK_TRAP	322
#define EATER_TRAP	323
#define COVETOUSNESS_TRAP	324
#define NOT_SEEN_TRAP	325
#define DARK_MODE_TRAP	326
#define ANTISEARCH_TRAP	327
#define HOMICIDE_TRAP	328
#define NASTY_NATION_TRAP	329
#define WAKEUP_CALL_TRAP	330
#define GRAYOUT_TRAP	331
#define GRAY_CENTER_TRAP	332
#define CHECKERBOARD_TRAP	333
#define CLOCKWISE_SPIN_TRAP	334
#define COUNTERCLOCKWISE_SPIN_TRAP	335
#define LAG_TRAP	336
#define BLESSCURSE_TRAP	337
#define DE_LIGHT_TRAP	338
#define DISCHARGE_TRAP	339
#define TRASHING_TRAP	340
#define FILTERING_TRAP	341
#define DEFORMATTING_TRAP	342
#define FLICKER_STRIP_TRAP	343
#define UNDRESSING_TRAP	344
#define HYPERBLUEWALL_TRAP	345
#define NOLITE_TRAP	346
#define PARANOIA_TRAP	347
#define FLEECESCRIPT_TRAP	348
#define INTERRUPT_TRAP	349
#define DUSTBIN_TRAP	350
#define MANA_BATTERY_TRAP	351
#define MONSTERFINGERS_TRAP	352
#define MISCAST_TRAP	353
#define MESSAGE_SUPPRESSION_TRAP	354
#define STUCK_ANNOUNCEMENT_TRAP	355
#define BLOODTHIRSTY_TRAP	356
#define MAXIMUM_DAMAGE_TRAP	357
#define LATENCY_TRAP	358
#define STARLIT_TRAP	359
#define KNOWLEDGE_TRAP	360
#define HIGHSCORE_TRAP	361
#define PINK_SPELL_TRAP	362
#define GREEN_SPELL_TRAP	363
#define EVC_TRAP	364
#define UNDERLAYER_TRAP	365
#define DAMAGE_METER_TRAP	366
#define ARBITRARY_WEIGHT_TRAP	367
#define FUCKED_INFO_TRAP	368
#define BLACK_SPELL_TRAP	369
#define CYAN_SPELL_TRAP	370
#define HEAP_TRAP	371
#define BLUE_SPELL_TRAP	372
#define TRON_TRAP	373
#define RED_SPELL_TRAP	374
#define TOO_HEAVY_TRAP	375
#define ELONGATION_TRAP	376
#define WRAPOVER_TRAP	377
#define DESTRUCTION_TRAP	378
#define MELEE_PREFIX_TRAP	379
#define AUTOMORE_TRAP	380
#define UNFAIR_ATTACK_TRAP	381

#define KOP_CUBE	382
#define BOSS_SPAWNER	383
#define CONTAMINATION_TRAP	384

#define EVIL_HEEL_TRAP 385
#define BAD_EQUIPMENT_TRAP 386
#define TEMPOCONFLICT_TRAP 387
#define TEMPOHUNGER_TRAP 388
#define TELEPORTITIS_TRAP 389
#define POLYMORPHITIS_TRAP 390
#define PREMATURE_DEATH_TRAP 391
#define LASTING_AMNESIA_TRAP 392
#define RAGNAROK_TRAP 393
#define SINGLE_DISENCHANT_TRAP 394
#define ACID_PIT 395

#define SEVERE_DISENCHANT_TRAP 396
#define PAIN_TRAP 397
#define TREMBLING_TRAP 398
#define TECHCAP_TRAP 399
#define SPELL_MEMORY_TRAP 400
#define SKILL_REDUCTION_TRAP 401
#define SKILLCAP_TRAP 402
#define PERMANENT_STAT_DAMAGE_TRAP 403

#define ORANGE_SPELL_TRAP 404
#define VIOLET_SPELL_TRAP 405
#define TRAP_OF_LONGING 406
#define CURSED_PART_TRAP 407
#define QUAVERSAL_TRAP 408
#define APPEARANCE_SHUFFLING_TRAP 409
#define BROWN_SPELL_TRAP 410
#define CHOICELESS_TRAP 411
#define GOLDSPELL_TRAP 412
#define DEPROVEMENT_TRAP 413
#define INITIALIZATION_TRAP 414
#define GUSHLUSH_TRAP 415
#define SOILTYPE_TRAP 416
#define DANGEROUS_TERRAIN_TRAP 417
#define FALLOUT_TRAP 418
#define MOJIBAKE_TRAP 419
#define GRAVATION_TRAP 420
#define UNCALLED_TRAP 421
#define EXPLODING_DICE_TRAP 422
#define PERMACURSE_TRAP 423
#define SHROUDED_IDENTITY_TRAP 424
#define FEELER_GAUGES_TRAP 425
#define LONG_SCREWUP_TRAP 426
#define WING_YELLOW_CHANGER 427
#define LIFE_SAVING_TRAP 428
#define CURSEUSE_TRAP 429
#define CUT_NUTRITION_TRAP 430
#define SKILL_LOSS_TRAP 431
#define AUTOPILOT_TRAP 432
#define FORCE_TRAP 433
#define MONSTER_GLYPH_TRAP 434
#define CHANGING_DIRECTIVE_TRAP 435
#define CONTAINER_KABOOM_TRAP 436
#define STEAL_DEGRADE_TRAP 437
#define LEFT_INVENTORY_TRAP 438
#define FLUCTUATING_SPEED_TRAP 439
#define TARMUSTROKINGNORA_TRAP 440
#define FAILURE_TRAP 441
#define BRIGHT_CYAN_SPELL_TRAP 442
#define FREQUENTATION_SPAWN_TRAP 443
#define PET_AI_TRAP 444
#define SATAN_TRAP 445
#define REMEMBERANCE_TRAP 446
#define POKELIE_TRAP 447
#define AUTOPICKUP_TRAP 448
#define DYWYPI_TRAP 449
#define SILVER_SPELL_TRAP 450
#define METAL_SPELL_TRAP 451
#define PLATINUM_SPELL_TRAP 452
#define MANLER_TRAP 453
#define DOORNING_TRAP 454
#define NOWNSIBLE_TRAP 455
#define ELM_STREET_TRAP 456
#define MONNOISE_TRAP 457
#define RANG_CALL_TRAP 458
#define RECURRING_SPELL_LOSS_TRAP 459
#define ANTITRAINING_TRAP 460
#define TECHOUT_TRAP 461
#define STAT_DECAY_TRAP 462
#define MOVEMORK_TRAP 463

#define HYBRID_TRAP 464
#define SHAPECHANGE_TRAP 465
#define MELTEM_TRAP 466
#define MIGUC_TRAP 467
#define DIRECTIVE_TRAP 468
#define SATATUE_TRAP 469
#define FARTING_WEB 470
#define CATACLYSM_TRAP 471
#define DATA_DELETE_TRAP 472
#define ELDER_TENTACLING_TRAP 473
#define FOOTERER_TRAP 474

#define BAD_PART_TRAP 475
#define COMPLETELY_BAD_PART_TRAP 476
#define EVIL_VARIANT_TRAP 477

#define TIMERUN_TRAP	478

#define TRAPNUM 479

#endif /* TRAP_H */
