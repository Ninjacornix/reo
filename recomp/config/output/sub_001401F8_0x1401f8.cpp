#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001401F8
// Address: 0x1401f8 - 0x1407e0
void sub_001401F8_0x1401f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001401F8_0x1401f8");
#endif

    switch (ctx->pc) {
        case 0x140218u: goto label_140218;
        case 0x140260u: goto label_140260;
        case 0x1402b0u: goto label_1402b0;
        case 0x1402d0u: goto label_1402d0;
        case 0x140348u: goto label_140348;
        case 0x140360u: goto label_140360;
        case 0x1403e4u: goto label_1403e4;
        case 0x140418u: goto label_140418;
        case 0x140478u: goto label_140478;
        case 0x1404a0u: goto label_1404a0;
        case 0x1404b8u: goto label_1404b8;
        case 0x140538u: goto label_140538;
        case 0x1405d0u: goto label_1405d0;
        case 0x1405f8u: goto label_1405f8;
        case 0x14066cu: goto label_14066c;
        case 0x140710u: goto label_140710;
        case 0x140780u: goto label_140780;
        case 0x1407b8u: goto label_1407b8;
        default: break;
    }

    ctx->pc = 0x1401f8u;

    // 0x1401f8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1401f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1401fc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1401fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140200: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x140200u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x140204: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x140204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x140208: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x140208u;
    {
        const bool branch_taken_0x140208 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x14020Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140208u;
            // 0x14020c: 0xac870014  sw          $a3, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140208) {
            ctx->pc = 0x140240u;
            goto label_140240;
        }
    }
    ctx->pc = 0x140210u;
    // 0x140210: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x140210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140214: 0x0  nop
    ctx->pc = 0x140214u;
    // NOP
label_140218:
    // 0x140218: 0xaca0000c  sw          $zero, 0xC($a1)
    ctx->pc = 0x140218u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 0));
    // 0x14021c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x14021cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x140220: 0x24a30010  addiu       $v1, $a1, 0x10
    ctx->pc = 0x140220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x140224: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x140224u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x140228: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x140228u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14022c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x14022cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x140230: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x140230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x140234: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x140234u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x140238: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x140238u;
    {
        const bool branch_taken_0x140238 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14023Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140238u;
            // 0x14023c: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140238) {
            ctx->pc = 0x140218u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140218;
        }
    }
    ctx->pc = 0x140240u;
label_140240:
    // 0x140240: 0x61100  sll         $v0, $a2, 4
    ctx->pc = 0x140240u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x140244: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140244u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140248: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x140248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x14024c: 0x24840024  addiu       $a0, $a0, 0x24
    ctx->pc = 0x14024cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 36));
    // 0x140250: 0xac40000c  sw          $zero, 0xC($v0)
    ctx->pc = 0x140250u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x140254: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x140254u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x140258: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x140258u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x14025c: 0x0  nop
    ctx->pc = 0x14025cu;
    // NOP
label_140260:
    // 0x140260: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x140260u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x140264: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x140264u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x140268: 0x0  nop
    ctx->pc = 0x140268u;
    // NOP
    // 0x14026c: 0x0  nop
    ctx->pc = 0x14026cu;
    // NOP
    // 0x140270: 0x0  nop
    ctx->pc = 0x140270u;
    // NOP
    // 0x140274: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x140274u;
    {
        const bool branch_taken_0x140274 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x140278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140274u;
            // 0x140278: 0x2484fffc  addiu       $a0, $a0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140274) {
            ctx->pc = 0x140260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140260;
        }
    }
    ctx->pc = 0x14027Cu;
    // 0x14027c: 0x3e00008  jr          $ra
    ctx->pc = 0x14027Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140284u;
    // 0x140284: 0x0  nop
    ctx->pc = 0x140284u;
    // NOP
    // 0x140288: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14028c: 0x2ca20004  sltiu       $v0, $a1, 0x4
    ctx->pc = 0x14028cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140290: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140290u;
    {
        const bool branch_taken_0x140290 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140290u;
            // 0x140294: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140290) {
            ctx->pc = 0x1402B8u;
            goto label_1402b8;
        }
    }
    ctx->pc = 0x140298u;
    // 0x140298: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x140298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x14029c: 0x50400014  beql        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x14029Cu;
    {
        const bool branch_taken_0x14029c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14029c) {
            ctx->pc = 0x1402A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14029Cu;
            // 0x1402a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1402F0u;
            goto label_1402f0;
        }
    }
    ctx->pc = 0x1402A4u;
    // 0x1402a4: 0x8c84002c  lw          $a0, 0x2C($a0)
    ctx->pc = 0x1402a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1402a8: 0x40f809  jalr        $v0
    ctx->pc = 0x1402A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1402B0u);
        ctx->pc = 0x1402ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402A8u;
            // 0x1402ac: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1402B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1402B0u; }
            if (ctx->pc != 0x1402B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1402B0u;
label_1402b0:
    // 0x1402b0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1402B0u;
    {
        const bool branch_taken_0x1402b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1402B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402B0u;
            // 0x1402b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402b0) {
            ctx->pc = 0x1402F0u;
            goto label_1402f0;
        }
    }
    ctx->pc = 0x1402B8u;
label_1402b8:
    // 0x1402b8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1402b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1402bc: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1402bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1402c0: 0x8c440018  lw          $a0, 0x18($v0)
    ctx->pc = 0x1402c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1402c4: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1402C4u;
    {
        const bool branch_taken_0x1402c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1402C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402C4u;
            // 0x1402c8: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402c4) {
            ctx->pc = 0x1402ECu;
            goto label_1402ec;
        }
    }
    ctx->pc = 0x1402CCu;
    // 0x1402cc: 0x0  nop
    ctx->pc = 0x1402ccu;
    // NOP
label_1402d0:
    // 0x1402d0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1402d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1402d4: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1402d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1402d8: 0x0  nop
    ctx->pc = 0x1402d8u;
    // NOP
    // 0x1402dc: 0x0  nop
    ctx->pc = 0x1402dcu;
    // NOP
    // 0x1402e0: 0x0  nop
    ctx->pc = 0x1402e0u;
    // NOP
    // 0x1402e4: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1402E4u;
    {
        const bool branch_taken_0x1402e4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1402E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402E4u;
            // 0x1402e8: 0x621821  addu        $v1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402e4) {
            ctx->pc = 0x1402D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1402d0;
        }
    }
    ctx->pc = 0x1402ECu;
label_1402ec:
    // 0x1402ec: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1402ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_1402f0:
    // 0x1402f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1402f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1402f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1402F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1402F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402F4u;
            // 0x1402f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1402FCu;
    // 0x1402fc: 0x0  nop
    ctx->pc = 0x1402fcu;
    // NOP
    // 0x140300: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x140300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x140304: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x140304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x140308: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140308u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14030c: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x14030cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140310: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x140310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x140314: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x140314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x140318: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x140318u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14031c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x14031cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x140320: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x140320u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140324: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x140324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x140328: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x140328u;
    {
        const bool branch_taken_0x140328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140328u;
            // 0x14032c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140328) {
            ctx->pc = 0x140358u;
            goto label_140358;
        }
    }
    ctx->pc = 0x140330u;
    // 0x140330: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140334: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x140334u;
    {
        const bool branch_taken_0x140334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140334) {
            ctx->pc = 0x140338u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140334u;
            // 0x140338: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14034Cu;
            goto label_14034c;
        }
    }
    ctx->pc = 0x14033Cu;
    // 0x14033c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14033cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140340: 0x40f809  jalr        $v0
    ctx->pc = 0x140340u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140348u);
        ctx->pc = 0x140344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140340u;
            // 0x140344: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140348u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140348u; }
            if (ctx->pc != 0x140348u) { return; }
        }
        }
    }
    ctx->pc = 0x140348u;
label_140348:
    // 0x140348: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x140348u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_14034c:
    // 0x14034c: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x14034Cu;
    {
        const bool branch_taken_0x14034c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14034Cu;
            // 0x140350: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14034c) {
            ctx->pc = 0x140418u;
            goto label_140418;
        }
    }
    ctx->pc = 0x140354u;
    // 0x140354: 0x0  nop
    ctx->pc = 0x140354u;
    // NOP
label_140358:
    // 0x140358: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140358u;
    SET_GPR_U32(ctx, 31, 0x140360u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140360u; }
        if (ctx->pc != 0x140360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140360u; }
        if (ctx->pc != 0x140360u) { return; }
    }
    ctx->pc = 0x140360u;
label_140360:
    // 0x140360: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x140360u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x140364: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x140364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x140368: 0x24450018  addiu       $a1, $v0, 0x18
    ctx->pc = 0x140368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x14036c: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x14036cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x140370: 0x10800025  beqz        $a0, . + 4 + (0x25 << 2)
    ctx->pc = 0x140370u;
    {
        const bool branch_taken_0x140370 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x140374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140370u;
            // 0x140374: 0x24920008  addiu       $s2, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140370) {
            ctx->pc = 0x140408u;
            goto label_140408;
        }
    }
    ctx->pc = 0x140378u;
    // 0x140378: 0x6a420007  ldl         $v0, 0x7($s2)
    ctx->pc = 0x140378u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x14037c: 0x6e420000  ldr         $v0, 0x0($s2)
    ctx->pc = 0x14037cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x140380: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x140380u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140384: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x140384u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140388: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x140388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14038c: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x14038cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x140390: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x140390u;
    {
        const bool branch_taken_0x140390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x140390) {
            ctx->pc = 0x140394u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140390u;
            // 0x140394: 0x82030005  lb          $v1, 0x5($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1403C0u;
            goto label_1403c0;
        }
    }
    ctx->pc = 0x140398u;
    // 0x140398: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x140398u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14039c: 0x6ba80007  ldl         $t0, 0x7($sp)
    ctx->pc = 0x14039cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1403a0: 0x6fa80000  ldr         $t0, 0x0($sp)
    ctx->pc = 0x1403a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1403a4: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x1403a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403a8: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x1403a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403ac: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1403acu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1403b0: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1403b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1403b4: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1403b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1403b8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1403B8u;
    {
        const bool branch_taken_0x1403b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1403BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1403B8u;
            // 0x1403bc: 0xae040014  sw          $a0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1403b8) {
            ctx->pc = 0x140410u;
            goto label_140410;
        }
    }
    ctx->pc = 0x1403C0u;
label_1403c0:
    // 0x1403c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1403c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1403c4: 0x54620011  bnel        $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1403C4u;
    {
        const bool branch_taken_0x1403c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1403c4) {
            ctx->pc = 0x1403C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1403C4u;
            // 0x1403c8: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14040Cu;
            goto label_14040c;
        }
    }
    ctx->pc = 0x1403CCu;
    // 0x1403cc: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x1403ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1403d0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1403d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403d4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1403d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403d8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1403d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1403dc: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1403DCu;
    SET_GPR_U32(ctx, 31, 0x1403E4u);
    ctx->pc = 0x1403E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1403DCu;
            // 0x1403e0: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1403E4u; }
        if (ctx->pc != 0x1403E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1403E4u; }
        if (ctx->pc != 0x1403E4u) { return; }
    }
    ctx->pc = 0x1403E4u;
label_1403e4:
    // 0x1403e4: 0x6ba80007  ldl         $t0, 0x7($sp)
    ctx->pc = 0x1403e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1403e8: 0x6fa80000  ldr         $t0, 0x0($sp)
    ctx->pc = 0x1403e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1403ec: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x1403ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403f0: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x1403f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1403f4: 0x6a050007  ldl         $a1, 0x7($s0)
    ctx->pc = 0x1403f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1403f8: 0x6e050000  ldr         $a1, 0x0($s0)
    ctx->pc = 0x1403f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1403fc: 0xb2450007  sdl         $a1, 0x7($s2)
    ctx->pc = 0x1403fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140400: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x140400u;
    {
        const bool branch_taken_0x140400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140400u;
            // 0x140404: 0xb6450000  sdr         $a1, 0x0($s2) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x140400) {
            ctx->pc = 0x140410u;
            goto label_140410;
        }
    }
    ctx->pc = 0x140408u;
label_140408:
    // 0x140408: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x140408u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_14040c:
    // 0x14040c: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x14040cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_140410:
    // 0x140410: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x140410u;
    SET_GPR_U32(ctx, 31, 0x140418u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140418u; }
        if (ctx->pc != 0x140418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140418u; }
        if (ctx->pc != 0x140418u) { return; }
    }
    ctx->pc = 0x140418u;
label_140418:
    // 0x140418: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x140418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14041c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x14041cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x140420: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x140420u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x140424: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x140424u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x140428: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x140428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14042c: 0x3e00008  jr          $ra
    ctx->pc = 0x14042Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14042Cu;
            // 0x140430: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140434u;
    // 0x140434: 0x0  nop
    ctx->pc = 0x140434u;
    // NOP
    // 0x140438: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14043c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x14043cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x140440: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140440u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140444: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x140444u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140448: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14044c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x14044cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140450: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x140450u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140454: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x140454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x140458: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140458u;
    {
        const bool branch_taken_0x140458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140458u;
            // 0x14045c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140458) {
            ctx->pc = 0x140480u;
            goto label_140480;
        }
    }
    ctx->pc = 0x140460u;
    // 0x140460: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140464: 0x50400044  beql        $v0, $zero, . + 4 + (0x44 << 2)
    ctx->pc = 0x140464u;
    {
        const bool branch_taken_0x140464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140464) {
            ctx->pc = 0x140468u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140464u;
            // 0x140468: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x14046Cu;
    // 0x14046c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14046cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140470: 0x40f809  jalr        $v0
    ctx->pc = 0x140470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140478u);
        ctx->pc = 0x140474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140470u;
            // 0x140474: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140478u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140478u; }
            if (ctx->pc != 0x140478u) { return; }
        }
        }
    }
    ctx->pc = 0x140478u;
label_140478:
    // 0x140478: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x140478u;
    {
        const bool branch_taken_0x140478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14047Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140478u;
            // 0x14047c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140478) {
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x140480u;
label_140480:
    // 0x140480: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x140480u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140484: 0x5840003c  blezl       $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x140484u;
    {
        const bool branch_taken_0x140484 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x140484) {
            ctx->pc = 0x140488u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140484u;
            // 0x140488: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x14048Cu;
    // 0x14048c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x14048cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x140490: 0x50400039  beql        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x140490u;
    {
        const bool branch_taken_0x140490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140490) {
            ctx->pc = 0x140494u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140490u;
            // 0x140494: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x140498u;
    // 0x140498: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140498u;
    SET_GPR_U32(ctx, 31, 0x1404A0u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1404A0u; }
        if (ctx->pc != 0x1404A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1404A0u; }
        if (ctx->pc != 0x1404A0u) { return; }
    }
    ctx->pc = 0x1404A0u;
label_1404a0:
    // 0x1404a0: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x1404a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1404a4: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1404a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1404a8: 0x24450018  addiu       $a1, $v0, 0x18
    ctx->pc = 0x1404a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x1404ac: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1404acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1404b0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1404B0u;
    {
        const bool branch_taken_0x1404b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1404B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1404B0u;
            // 0x1404b4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1404b0) {
            ctx->pc = 0x1404D4u;
            goto label_1404d4;
        }
    }
    ctx->pc = 0x1404B8u;
label_1404b8:
    // 0x1404b8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1404b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1404bc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1404bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1404c0: 0x0  nop
    ctx->pc = 0x1404c0u;
    // NOP
    // 0x1404c4: 0x0  nop
    ctx->pc = 0x1404c4u;
    // NOP
    // 0x1404c8: 0x0  nop
    ctx->pc = 0x1404c8u;
    // NOP
    // 0x1404cc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1404CCu;
    {
        const bool branch_taken_0x1404cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1404D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1404CCu;
            // 0x1404d0: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1404cc) {
            ctx->pc = 0x1404B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1404b8;
        }
    }
    ctx->pc = 0x1404D4u;
label_1404d4:
    // 0x1404d4: 0x82030005  lb          $v1, 0x5($s0)
    ctx->pc = 0x1404d4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1404d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1404d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1404dc: 0x5462000e  bnel        $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1404DCu;
    {
        const bool branch_taken_0x1404dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1404dc) {
            ctx->pc = 0x1404E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404DCu;
            // 0x1404e0: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x1404E4u;
    // 0x1404e4: 0x5080000c  beql        $a0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1404E4u;
    {
        const bool branch_taken_0x1404e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1404e4) {
            ctx->pc = 0x1404E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404E4u;
            // 0x1404e8: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x1404ECu;
    // 0x1404ec: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1404ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1404f0: 0x8c86000c  lw          $a2, 0xC($a0)
    ctx->pc = 0x1404f0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1404f4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1404f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1404f8: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1404f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1404fc: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1404FCu;
    {
        const bool branch_taken_0x1404fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1404fc) {
            ctx->pc = 0x140500u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404FCu;
            // 0x140500: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x140504u;
    // 0x140504: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x140504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140508: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x140508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x14050c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x14050Cu;
    {
        const bool branch_taken_0x14050c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14050Cu;
            // 0x140510: 0xac82000c  sw          $v0, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14050c) {
            ctx->pc = 0x14055Cu;
            goto label_14055c;
        }
    }
    ctx->pc = 0x140514u;
    // 0x140514: 0x0  nop
    ctx->pc = 0x140514u;
    // NOP
label_140518:
    // 0x140518: 0x54800009  bnel        $a0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x140518u;
    {
        const bool branch_taken_0x140518 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x140518) {
            ctx->pc = 0x14051Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140518u;
            // 0x14051c: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140540u;
            goto label_140540;
        }
    }
    ctx->pc = 0x140520u;
    // 0x140520: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140524: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x140524u;
    {
        const bool branch_taken_0x140524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140524) {
            ctx->pc = 0x140528u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140524u;
            // 0x140528: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140560u;
            goto label_140560;
        }
    }
    ctx->pc = 0x14052Cu;
    // 0x14052c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14052cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140530: 0x40f809  jalr        $v0
    ctx->pc = 0x140530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140538u);
        ctx->pc = 0x140534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140530u;
            // 0x140534: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140538u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140538u; }
            if (ctx->pc != 0x140538u) { return; }
        }
        }
    }
    ctx->pc = 0x140538u;
label_140538:
    // 0x140538: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x140538u;
    {
        const bool branch_taken_0x140538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14053Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140538u;
            // 0x14053c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140538) {
            ctx->pc = 0x140560u;
            goto label_140560;
        }
    }
    ctx->pc = 0x140540u;
label_140540:
    // 0x140540: 0x6a230007  ldl         $v1, 0x7($s1)
    ctx->pc = 0x140540u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x140544: 0x6e230000  ldr         $v1, 0x0($s1)
    ctx->pc = 0x140544u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x140548: 0xb083000f  sdl         $v1, 0xF($a0)
    ctx->pc = 0x140548u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14054c: 0xb4830008  sdr         $v1, 0x8($a0)
    ctx->pc = 0x14054cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140550: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x140550u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x140554: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x140554u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x140558: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140558u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
label_14055c:
    // 0x14055c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14055cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_140560:
    // 0x140560: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140560u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140564: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x140564u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140568: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x140568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14056c: 0x804fc9c  j           func_13F270
    ctx->pc = 0x14056Cu;
    ctx->pc = 0x140570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14056Cu;
            // 0x140570: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140574u;
    // 0x140574: 0x0  nop
    ctx->pc = 0x140574u;
    // NOP
label_140578:
    // 0x140578: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140578u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14057c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x14057cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140580: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x140580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x140584: 0x3e00008  jr          $ra
    ctx->pc = 0x140584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140584u;
            // 0x140588: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14058Cu;
    // 0x14058c: 0x0  nop
    ctx->pc = 0x14058cu;
    // NOP
    // 0x140590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140594: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x140594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x140598: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140598u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14059c: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x14059cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1405a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1405a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1405a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1405a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1405a8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1405a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1405ac: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1405acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1405b0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1405B0u;
    {
        const bool branch_taken_0x1405b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1405B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405B0u;
            // 0x1405b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1405b0) {
            ctx->pc = 0x1405D8u;
            goto label_1405d8;
        }
    }
    ctx->pc = 0x1405B8u;
    // 0x1405b8: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x1405b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1405bc: 0x50400040  beql        $v0, $zero, . + 4 + (0x40 << 2)
    ctx->pc = 0x1405BCu;
    {
        const bool branch_taken_0x1405bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1405bc) {
            ctx->pc = 0x1405C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405BCu;
            // 0x1405c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405C4u;
    // 0x1405c4: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x1405c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1405c8: 0x40f809  jalr        $v0
    ctx->pc = 0x1405C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1405D0u);
        ctx->pc = 0x1405CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405C8u;
            // 0x1405cc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1405D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1405D0u; }
            if (ctx->pc != 0x1405D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1405D0u;
label_1405d0:
    // 0x1405d0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1405D0u;
    {
        const bool branch_taken_0x1405d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1405D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405D0u;
            // 0x1405d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1405d0) {
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405D8u;
label_1405d8:
    // 0x1405d8: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1405d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1405dc: 0x58400038  blezl       $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x1405DCu;
    {
        const bool branch_taken_0x1405dc = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1405dc) {
            ctx->pc = 0x1405E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405DCu;
            // 0x1405e0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405E4u;
    // 0x1405e4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1405e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1405e8: 0x50400035  beql        $v0, $zero, . + 4 + (0x35 << 2)
    ctx->pc = 0x1405E8u;
    {
        const bool branch_taken_0x1405e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1405e8) {
            ctx->pc = 0x1405ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405E8u;
            // 0x1405ec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405F0u;
    // 0x1405f0: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x1405F0u;
    SET_GPR_U32(ctx, 31, 0x1405F8u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1405F8u; }
        if (ctx->pc != 0x1405F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1405F8u; }
        if (ctx->pc != 0x1405F8u) { return; }
    }
    ctx->pc = 0x1405F8u;
label_1405f8:
    // 0x1405f8: 0x122880  sll         $a1, $s2, 2
    ctx->pc = 0x1405f8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1405fc: 0x26080008  addiu       $t0, $s0, 0x8
    ctx->pc = 0x1405fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x140600: 0x82020005  lb          $v0, 0x5($s0)
    ctx->pc = 0x140600u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x140604: 0xa81821  addu        $v1, $a1, $t0
    ctx->pc = 0x140604u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x140608: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x140608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14060c: 0x1444000e  bne         $v0, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x14060Cu;
    {
        const bool branch_taken_0x14060c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x140610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14060Cu;
            // 0x140610: 0x8c660010  lw          $a2, 0x10($v1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14060c) {
            ctx->pc = 0x140648u;
            goto label_140648;
        }
    }
    ctx->pc = 0x140614u;
    // 0x140614: 0x50c0000d  beql        $a2, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x140614u;
    {
        const bool branch_taken_0x140614 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x140614) {
            ctx->pc = 0x140618u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140614u;
            // 0x140618: 0x8e060014  lw          $a2, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14064Cu;
            goto label_14064c;
        }
    }
    ctx->pc = 0x14061Cu;
    // 0x14061c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x14061cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x140620: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x140620u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140624: 0x8cc30008  lw          $v1, 0x8($a2)
    ctx->pc = 0x140624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x140628: 0x871021  addu        $v0, $a0, $a3
    ctx->pc = 0x140628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x14062c: 0x54430007  bnel        $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x14062Cu;
    {
        const bool branch_taken_0x14062c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x14062c) {
            ctx->pc = 0x140630u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14062Cu;
            // 0x140630: 0x8e060014  lw          $a2, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14064Cu;
            goto label_14064c;
        }
    }
    ctx->pc = 0x140634u;
    // 0x140634: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x140634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x140638: 0xacc40008  sw          $a0, 0x8($a2)
    ctx->pc = 0x140638u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 4));
    // 0x14063c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x14063cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x140640: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x140640u;
    {
        const bool branch_taken_0x140640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140640u;
            // 0x140644: 0xacc2000c  sw          $v0, 0xC($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140640) {
            ctx->pc = 0x1406A4u;
            goto label_1406a4;
        }
    }
    ctx->pc = 0x140648u;
label_140648:
    // 0x140648: 0x8e060014  lw          $a2, 0x14($s0)
    ctx->pc = 0x140648u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_14064c:
    // 0x14064c: 0x54c0000a  bnel        $a2, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x14064Cu;
    {
        const bool branch_taken_0x14064c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x14064c) {
            ctx->pc = 0x140650u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14064Cu;
            // 0x140650: 0x8cc20000  lw          $v0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140678u;
            goto label_140678;
        }
    }
    ctx->pc = 0x140654u;
    // 0x140654: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140658: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x140658u;
    {
        const bool branch_taken_0x140658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140658) {
            ctx->pc = 0x14065Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140658u;
            // 0x14065c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406A8u;
            goto label_1406a8;
        }
    }
    ctx->pc = 0x140660u;
    // 0x140660: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x140660u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140664: 0x40f809  jalr        $v0
    ctx->pc = 0x140664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x14066Cu);
        ctx->pc = 0x140668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140664u;
            // 0x140668: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x14066Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x14066Cu; }
            if (ctx->pc != 0x14066Cu) { return; }
        }
        }
    }
    ctx->pc = 0x14066Cu;
label_14066c:
    // 0x14066c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x14066Cu;
    {
        const bool branch_taken_0x14066c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14066Cu;
            // 0x140670: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14066c) {
            ctx->pc = 0x1406A8u;
            goto label_1406a8;
        }
    }
    ctx->pc = 0x140674u;
    // 0x140674: 0x0  nop
    ctx->pc = 0x140674u;
    // NOP
label_140678:
    // 0x140678: 0x24a30010  addiu       $v1, $a1, 0x10
    ctx->pc = 0x140678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x14067c: 0x1031821  addu        $v1, $t0, $v1
    ctx->pc = 0x14067cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x140680: 0x6a240007  ldl         $a0, 0x7($s1)
    ctx->pc = 0x140680u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x140684: 0x6e240000  ldr         $a0, 0x0($s1)
    ctx->pc = 0x140684u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x140688: 0xb0c4000f  sdl         $a0, 0xF($a2)
    ctx->pc = 0x140688u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14068c: 0xb4c40008  sdr         $a0, 0x8($a2)
    ctx->pc = 0x14068cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140690: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x140690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x140694: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x140694u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x140698: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14069c: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x14069cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1406a0: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x1406a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
label_1406a4:
    // 0x1406a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1406a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1406a8:
    // 0x1406a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1406a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1406ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1406acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1406b0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1406b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1406b4: 0x804fc9c  j           func_13F270
    ctx->pc = 0x1406B4u;
    ctx->pc = 0x1406B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1406B4u;
            // 0x1406b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1406BCu;
    // 0x1406bc: 0x0  nop
    ctx->pc = 0x1406bcu;
    // NOP
label_1406c0:
    // 0x1406c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1406c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1406c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1406c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1406c8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1406c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1406cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1406CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1406D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1406CCu;
            // 0x1406d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1406D4u;
    // 0x1406d4: 0x0  nop
    ctx->pc = 0x1406d4u;
    // NOP
    // 0x1406d8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1406d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1406dc: 0x2ca50004  sltiu       $a1, $a1, 0x4
    ctx->pc = 0x1406dcu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1406e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1406e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1406e4: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1406e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1406e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1406e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1406ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1406ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1406f0: 0x14a00009  bnez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1406F0u;
    {
        const bool branch_taken_0x1406f0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1406F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1406F0u;
            // 0x1406f4: 0xace00000  sw          $zero, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1406f0) {
            ctx->pc = 0x140718u;
            goto label_140718;
        }
    }
    ctx->pc = 0x1406F8u;
    // 0x1406f8: 0x8d020028  lw          $v0, 0x28($t0)
    ctx->pc = 0x1406f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 40)));
    // 0x1406fc: 0x50400016  beql        $v0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x1406FCu;
    {
        const bool branch_taken_0x1406fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1406fc) {
            ctx->pc = 0x140700u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1406FCu;
            // 0x140700: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140704u;
    // 0x140704: 0x8d04002c  lw          $a0, 0x2C($t0)
    ctx->pc = 0x140704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 44)));
    // 0x140708: 0x40f809  jalr        $v0
    ctx->pc = 0x140708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140710u);
        ctx->pc = 0x14070Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140708u;
            // 0x14070c: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140710u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140710u; }
            if (ctx->pc != 0x140710u) { return; }
        }
        }
    }
    ctx->pc = 0x140710u;
label_140710:
    // 0x140710: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x140710u;
    {
        const bool branch_taken_0x140710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140710u;
            // 0x140714: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140710) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140718u;
label_140718:
    // 0x140718: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x140718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x14071c: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x14071Cu;
    {
        const bool branch_taken_0x14071c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x140720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14071Cu;
            // 0x140720: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14071c) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140724u;
    // 0x140724: 0x6862000f  ldl         $v0, 0xF($v1)
    ctx->pc = 0x140724u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x140728: 0x6c620008  ldr         $v0, 0x8($v1)
    ctx->pc = 0x140728u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x14072c: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x14072cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140730: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x140730u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140734: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x140734u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140738: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x140738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14073c: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x14073cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x140740: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x140740u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x140744: 0x663026  xor         $a2, $v1, $a2
    ctx->pc = 0x140744u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 6));
    // 0x140748: 0x81030005  lb          $v1, 0x5($t0)
    ctx->pc = 0x140748u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 5)));
    // 0x14074c: 0x10640002  beq         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x14074Cu;
    {
        const bool branch_taken_0x14074c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x140750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14074Cu;
            // 0x140750: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x14074c) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140754u;
    // 0x140754: 0x2cc20001  sltiu       $v0, $a2, 0x1
    ctx->pc = 0x140754u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_140758:
    // 0x140758: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14075c: 0x3e00008  jr          $ra
    ctx->pc = 0x14075Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14075Cu;
            // 0x140760: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140764u;
    // 0x140764: 0x0  nop
    ctx->pc = 0x140764u;
    // NOP
    // 0x140768: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x140768u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x14076c: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x14076cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x140770: 0x8ca30018  lw          $v1, 0x18($a1)
    ctx->pc = 0x140770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x140774: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x140774u;
    {
        const bool branch_taken_0x140774 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x140778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140774u;
            // 0x140778: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140774) {
            ctx->pc = 0x14079Cu;
            goto label_14079c;
        }
    }
    ctx->pc = 0x14077Cu;
    // 0x14077c: 0x0  nop
    ctx->pc = 0x14077cu;
    // NOP
label_140780:
    // 0x140780: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x140780u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140784: 0x0  nop
    ctx->pc = 0x140784u;
    // NOP
    // 0x140788: 0x0  nop
    ctx->pc = 0x140788u;
    // NOP
    // 0x14078c: 0x0  nop
    ctx->pc = 0x14078cu;
    // NOP
    // 0x140790: 0x0  nop
    ctx->pc = 0x140790u;
    // NOP
    // 0x140794: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x140794u;
    {
        const bool branch_taken_0x140794 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x140798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140794u;
            // 0x140798: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140794) {
            ctx->pc = 0x140780u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140780;
        }
    }
    ctx->pc = 0x14079Cu;
label_14079c:
    // 0x14079c: 0x3e00008  jr          $ra
    ctx->pc = 0x14079Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1407A4u;
    // 0x1407a4: 0x0  nop
    ctx->pc = 0x1407a4u;
    // NOP
    // 0x1407a8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1407a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1407ac: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1407ACu;
    {
        const bool branch_taken_0x1407ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1407B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1407ACu;
            // 0x1407b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1407ac) {
            ctx->pc = 0x1407D4u;
            goto label_1407d4;
        }
    }
    ctx->pc = 0x1407B4u;
    // 0x1407b4: 0x0  nop
    ctx->pc = 0x1407b4u;
    // NOP
label_1407b8:
    // 0x1407b8: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1407b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1407bc: 0x0  nop
    ctx->pc = 0x1407bcu;
    // NOP
    // 0x1407c0: 0x0  nop
    ctx->pc = 0x1407c0u;
    // NOP
    // 0x1407c4: 0x0  nop
    ctx->pc = 0x1407c4u;
    // NOP
    // 0x1407c8: 0x0  nop
    ctx->pc = 0x1407c8u;
    // NOP
    // 0x1407cc: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1407CCu;
    {
        const bool branch_taken_0x1407cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1407D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1407CCu;
            // 0x1407d0: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1407cc) {
            ctx->pc = 0x1407B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1407b8;
        }
    }
    ctx->pc = 0x1407D4u;
label_1407d4:
    // 0x1407d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1407D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140218u: goto label_140218;
            case 0x140240u: goto label_140240;
            case 0x140260u: goto label_140260;
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            case 0x140348u: goto label_140348;
            case 0x14034Cu: goto label_14034c;
            case 0x140358u: goto label_140358;
            case 0x140360u: goto label_140360;
            case 0x1403C0u: goto label_1403c0;
            case 0x1403E4u: goto label_1403e4;
            case 0x140408u: goto label_140408;
            case 0x14040Cu: goto label_14040c;
            case 0x140410u: goto label_140410;
            case 0x140418u: goto label_140418;
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1407DCu;
    // 0x1407dc: 0x0  nop
    ctx->pc = 0x1407dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
