# Original option editing and save-before-return confirmation

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed,
including all twelve owned option-table arms and confirmation phases. Addresses/
offsets hexadecimal; W=755EC0. No game/build/replay/attachment/live-memory work.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6ECDE0](../recomp/config/output_ovl/o2/o2_006ECDE0_0x6ecde0.cpp) | `tick_original_options_edit_defaults_quit_confirmation_and_saved_snapshot_candidate` | High role; full body/table reviewed | Reads combined324210/324228 input and4BAE90 direct bits. W0=0 resets auxiliary UI6DF230, sets state1/selectionW1=A/W2=0, enables renderC680 and returns; W0=1 processes options. When1B0300==1, input324210 bit4000 closes UI/restoresDDD70(0). With W2==0, combined1/2 moves W1 cyclic0..A and returns after sound. Owned742D90 dispatch0..B: controller type3243EC cycles0..5; vibration3243EF toggles and newly enabled1 calls1BA9F0(2); mono3243C5 toggles and applies1B86C0; BGM/SE3243C9/CA change within0..7 and apply1B8780/86F0. Brightness3243F0 uses center80, positive-side step1, negative-side step2 and endpoint guards39/A4; screen signedED changes1 andEE changes2 with original comparison thresholds-9/A, applying1AF790. Default action input20 writes type0,vibration1,mono0,brightness80,volumes7,screen0 and applies audio/screen helpers. Quit selection9 opens W2=1, answerW3 defaults1; left/right changes answer, confirm either resets modal or chooses W1=B/W2=A countdown. Exit selectionA closes/restores resources. W1=B decrements countdown, at0 calls669A00(local actor), sets4BAE77/76, closes and possibly324489. Common tail1AEDB0 copies live option bytes to in-memory saved snapshot; no file persistence proven here. |
| [o2 0x6ED6D0](../recomp/config/output_ovl/o2/o2_006ED6D0_0x6ed6d0.cpp) | `tick_save_game_and_return_confirmation_snapshot_and_completion_candidate` | High UI purpose; helper completion semantics candidate | W0 phases0..3. Phase0 calls6DF230/C680, clears324488, captures session snapshot37EB10, sets answerW1=1 and state1, then falls through input handling. Combined324210/324228 masks8/4 select1/0; direct4BAE90 bit20 with answer1 cancels through1430/DDD70(0), clearing4BAE97/94. Answer0 clears cache flags4BAE7E/7C/7D, sets324488=1, stores37B910(scenario3243DA)+1 in32448D, saves324476 toW3DE1, calls1C2600(3,1), advances to phase2. Phase1 also draws owned save-and-main-menu question with colored YES/NO text. Phase2 polls1C2940 until zero, then1C1260 result>=0 and unchanged324476 produce4BAE97=2/state3; failure/identity change clears324488/48D and resets state0. Phase3 has no further work. External save helper/file outcome not independently validated; no host file was touched. |

Owned table742D90 contains twelve internal destinations in numeric order:
6ECF54,6ECFDC,6ED054,6ED0D0,6ED158,6ED1E0,6ED2FC,6ED398,6ED434,
6ED4D4,6ED5EC,6ED634. These are branches of6ECDE0, not extra functions.
Horizontal option input uses masks8/4; direct confirm20 is separate. Exact guard
comparisons and step sizes are retained rather than translated into guessed
player-visible percentages or unrestricted clamping rules.

Owned7344D0 strings ask 'Will you save the game and' / 'return to the main menu?'.
Strings742E10/18/20/28 supply YES,/NO,YES/,NO. Unlike its ordinary quit path,
this flow captures the already-mapped compact world/actor resume snapshot before
starting the external helper. That capture alone does not establish durable save
success. The option renderer is in
[map/options render callback](SYMBOLS_MAP_OPTIONS_RENDER_CALLBACK.md); original
font calls remain subject to the [native font override boundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md).

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
