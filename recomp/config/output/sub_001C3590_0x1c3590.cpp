#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C3590
// Address: 0x1c3590 - 0x1c3950
void sub_001C3590_0x1c3590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C3590_0x1c3590");
#endif

    switch (ctx->pc) {
        case 0x1c35f4u: goto label_1c35f4;
        case 0x1c3604u: goto label_1c3604;
        case 0x1c36a8u: goto label_1c36a8;
        case 0x1c36c0u: goto label_1c36c0;
        case 0x1c372cu: goto label_1c372c;
        case 0x1c375cu: goto label_1c375c;
        case 0x1c3798u: goto label_1c3798;
        case 0x1c37a4u: goto label_1c37a4;
        case 0x1c37fcu: goto label_1c37fc;
        case 0x1c3880u: goto label_1c3880;
        case 0x1c391cu: goto label_1c391c;
        case 0x1c3930u: goto label_1c3930;
        case 0x1c3938u: goto label_1c3938;
        default: break;
    }

    ctx->pc = 0x1c3590u;

    // 0x1c3590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c3590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c3594: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c3594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c3598: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c3598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c359c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c359cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c35a0: 0x80830002  lb          $v1, 0x2($a0)
    ctx->pc = 0x1c35a0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c35a4: 0x106200d7  beq         $v1, $v0, . + 4 + (0xD7 << 2)
    ctx->pc = 0x1C35A4u;
    {
        const bool branch_taken_0x1c35a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C35A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C35A4u;
            // 0x1c35a8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c35a4) {
            ctx->pc = 0x1C3904u;
            goto label_1c3904;
        }
    }
    ctx->pc = 0x1C35ACu;
    // 0x1c35ac: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c35acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c35b0: 0x106200b1  beq         $v1, $v0, . + 4 + (0xB1 << 2)
    ctx->pc = 0x1C35B0u;
    {
        const bool branch_taken_0x1c35b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C35B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C35B0u;
            // 0x1c35b4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c35b0) {
            ctx->pc = 0x1C3878u;
            goto label_1c3878;
        }
    }
    ctx->pc = 0x1C35B8u;
    // 0x1c35b8: 0x1062005a  beq         $v1, $v0, . + 4 + (0x5A << 2)
    ctx->pc = 0x1C35B8u;
    {
        const bool branch_taken_0x1c35b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C35BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C35B8u;
            // 0x1c35bc: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c35b8) {
            ctx->pc = 0x1C3724u;
            goto label_1c3724;
        }
    }
    ctx->pc = 0x1C35C0u;
    // 0x1c35c0: 0x1066000e  beq         $v1, $a2, . + 4 + (0xE << 2)
    ctx->pc = 0x1C35C0u;
    {
        const bool branch_taken_0x1c35c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        if (branch_taken_0x1c35c0) {
            ctx->pc = 0x1C35FCu;
            goto label_1c35fc;
        }
    }
    ctx->pc = 0x1C35C8u;
    // 0x1c35c8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C35C8u;
    {
        const bool branch_taken_0x1c35c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c35c8) {
            ctx->pc = 0x1C35D8u;
            goto label_1c35d8;
        }
    }
    ctx->pc = 0x1C35D0u;
    // 0x1c35d0: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x1C35D0u;
    {
        const bool branch_taken_0x1c35d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C35D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C35D0u;
            // 0x1c35d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c35d0) {
            ctx->pc = 0x1C3928u;
            goto label_1c3928;
        }
    }
    ctx->pc = 0x1C35D8u;
label_1c35d8:
    // 0x1c35d8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c35d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c35dc: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1c35dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1c35e0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c35e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c35e4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c35e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c35e8: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c35e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c35ec: 0xc0701c4  jal         func_1C0710
    ctx->pc = 0x1C35ECu;
    SET_GPR_U32(ctx, 31, 0x1C35F4u);
    ctx->pc = 0x1C35F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C35ECu;
            // 0x1c35f0: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0710u;
    if (runtime->hasFunction(0x1C0710u)) {
        auto targetFn = runtime->lookupFunction(0x1C0710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C35F4u; }
        if (ctx->pc != 0x1C35F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0710_0x1c0710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C35F4u; }
        if (ctx->pc != 0x1C35F4u) { return; }
    }
    ctx->pc = 0x1C35F4u;
label_1c35f4:
    // 0x1c35f4: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1c35f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c35f8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c35f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_1c35fc:
    // 0x1c35fc: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C35FCu;
    SET_GPR_U32(ctx, 31, 0x1C3604u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3604u; }
        if (ctx->pc != 0x1C3604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3604u; }
        if (ctx->pc != 0x1C3604u) { return; }
    }
    ctx->pc = 0x1C3604u;
label_1c3604:
    // 0x1c3604: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c3604u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c3608: 0x104300c6  beq         $v0, $v1, . + 4 + (0xC6 << 2)
    ctx->pc = 0x1C3608u;
    {
        const bool branch_taken_0x1c3608 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3608) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3610u;
    // 0x1c3610: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1C3610u;
    {
        const bool branch_taken_0x1c3610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3610u;
            // 0x1c3614: 0x2403ff05  addiu       $v1, $zero, -0xFB (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3610) {
            ctx->pc = 0x1C369Cu;
            goto label_1c369c;
        }
    }
    ctx->pc = 0x1C3618u;
    // 0x1c3618: 0x10430019  beq         $v0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1C3618u;
    {
        const bool branch_taken_0x1c3618 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3618) {
            ctx->pc = 0x1C3680u;
            goto label_1c3680;
        }
    }
    ctx->pc = 0x1C3620u;
    // 0x1c3620: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c3620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c3624: 0x1043000f  beq         $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1C3624u;
    {
        const bool branch_taken_0x1c3624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C3628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3624u;
            // 0x1c3628: 0x2403ff02  addiu       $v1, $zero, -0xFE (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3624) {
            ctx->pc = 0x1C3664u;
            goto label_1c3664;
        }
    }
    ctx->pc = 0x1C362Cu;
    // 0x1c362c: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C362Cu;
    {
        const bool branch_taken_0x1c362c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c362c) {
            ctx->pc = 0x1C3648u;
            goto label_1c3648;
        }
    }
    ctx->pc = 0x1C3634u;
    // 0x1c3634: 0x2403ff03  addiu       $v1, $zero, -0xFD
    ctx->pc = 0x1c3634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c3638: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3638u;
    {
        const bool branch_taken_0x1c3638 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3638) {
            ctx->pc = 0x1C3648u;
            goto label_1c3648;
        }
    }
    ctx->pc = 0x1C3640u;
    // 0x1c3640: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1C3640u;
    {
        const bool branch_taken_0x1c3640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3640u;
            // 0x1c3644: 0x304200ff  andi        $v0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3640) {
            ctx->pc = 0x1C36C8u;
            goto label_1c36c8;
        }
    }
    ctx->pc = 0x1C3648u;
label_1c3648:
    // 0x1c3648: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c3648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c364c: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c364cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c3650: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3650u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3654: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3658: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3658u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c365c: 0x100000b1  b           . + 4 + (0xB1 << 2)
    ctx->pc = 0x1C365Cu;
    {
        const bool branch_taken_0x1c365c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C365Cu;
            // 0x1c3660: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c365c) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3664u;
label_1c3664:
    // 0x1c3664: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c3664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c3668: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c3668u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c366c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c366cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3670: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3670u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3674: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3674u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3678: 0x100000aa  b           . + 4 + (0xAA << 2)
    ctx->pc = 0x1C3678u;
    {
        const bool branch_taken_0x1c3678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C367Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3678u;
            // 0x1c367c: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3678) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3680u;
label_1c3680:
    // 0x1c3680: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c3680u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c3684: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c3684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c3688: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3688u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c368c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c368cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3690: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3690u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3694: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1C3694u;
    {
        const bool branch_taken_0x1c3694 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3694u;
            // 0x1c3698: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3694) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C369Cu;
label_1c369c:
    // 0x1c369c: 0x8e0500ec  lw          $a1, 0xEC($s0)
    ctx->pc = 0x1c369cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x1c36a0: 0xc070138  jal         func_1C04E0
    ctx->pc = 0x1C36A0u;
    SET_GPR_U32(ctx, 31, 0x1C36A8u);
    ctx->pc = 0x1C36A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C36A0u;
            // 0x1c36a4: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C04E0u;
    if (runtime->hasFunction(0x1C04E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C04E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C36A8u; }
        if (ctx->pc != 0x1C36A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C04E0_0x1c04e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C36A8u; }
        if (ctx->pc != 0x1C36A8u) { return; }
    }
    ctx->pc = 0x1C36A8u;
label_1c36a8:
    // 0x1c36a8: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x1c36a8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c36ac: 0x24020026  addiu       $v0, $zero, 0x26
    ctx->pc = 0x1c36acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
    // 0x1c36b0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c36b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c36b4: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c36b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c36b8: 0xc0704a4  jal         func_1C1290
    ctx->pc = 0x1C36B8u;
    SET_GPR_U32(ctx, 31, 0x1C36C0u);
    ctx->pc = 0x1C36BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C36B8u;
            // 0x1c36bc: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1290u;
    if (runtime->hasFunction(0x1C1290u)) {
        auto targetFn = runtime->lookupFunction(0x1C1290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C36C0u; }
        if (ctx->pc != 0x1C36C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1290_0x1c1290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C36C0u; }
        if (ctx->pc != 0x1C36C0u) { return; }
    }
    ctx->pc = 0x1C36C0u;
label_1c36c0:
    // 0x1c36c0: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1C36C0u;
    {
        const bool branch_taken_0x1c36c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c36c0) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C36C8u;
label_1c36c8:
    // 0x1c36c8: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c36c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c36cc: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c36ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c36d0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c36d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c36d4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c36d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c36d8: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1c36d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c36dc: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1C36DCu;
    {
        const bool branch_taken_0x1c36dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c36dc) {
            ctx->pc = 0x1C3718u;
            goto label_1c3718;
        }
    }
    ctx->pc = 0x1C36E4u;
    // 0x1c36e4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c36e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c36e8: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C36E8u;
    {
        const bool branch_taken_0x1c36e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C36ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C36E8u;
            // 0x1c36ec: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c36e8) {
            ctx->pc = 0x1C371Cu;
            goto label_1c371c;
        }
    }
    ctx->pc = 0x1C36F0u;
    // 0x1c36f0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c36f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c36f4: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C36F4u;
    {
        const bool branch_taken_0x1c36f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C36F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C36F4u;
            // 0x1c36f8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c36f4) {
            ctx->pc = 0x1C3718u;
            goto label_1c3718;
        }
    }
    ctx->pc = 0x1C36FCu;
    // 0x1c36fc: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C36FCu;
    {
        const bool branch_taken_0x1c36fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c36fc) {
            ctx->pc = 0x1C370Cu;
            goto label_1c370c;
        }
    }
    ctx->pc = 0x1C3704u;
    // 0x1c3704: 0x10000087  b           . + 4 + (0x87 << 2)
    ctx->pc = 0x1C3704u;
    {
        const bool branch_taken_0x1c3704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3704) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C370Cu;
label_1c370c:
    // 0x1c370c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c370cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c3710: 0x10000084  b           . + 4 + (0x84 << 2)
    ctx->pc = 0x1C3710u;
    {
        const bool branch_taken_0x1c3710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3710u;
            // 0x1c3714: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3710) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3718u;
label_1c3718:
    // 0x1c3718: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c3718u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_1c371c:
    // 0x1c371c: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x1C371Cu;
    {
        const bool branch_taken_0x1c371c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C371Cu;
            // 0x1c3720: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c371c) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3724u;
label_1c3724:
    // 0x1c3724: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C3724u;
    SET_GPR_U32(ctx, 31, 0x1C372Cu);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C372Cu; }
        if (ctx->pc != 0x1C372Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C372Cu; }
        if (ctx->pc != 0x1C372Cu) { return; }
    }
    ctx->pc = 0x1C372Cu;
label_1c372c:
    // 0x1c372c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c372cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c3730: 0x1043004d  beq         $v0, $v1, . + 4 + (0x4D << 2)
    ctx->pc = 0x1C3730u;
    {
        const bool branch_taken_0x1c3730 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3730) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C3738u;
    // 0x1c3738: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c3738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c373c: 0x10430028  beq         $v0, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1C373Cu;
    {
        const bool branch_taken_0x1c373c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c373c) {
            ctx->pc = 0x1C37E0u;
            goto label_1c37e0;
        }
    }
    ctx->pc = 0x1C3744u;
    // 0x1c3744: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3744u;
    {
        const bool branch_taken_0x1c3744 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3744u;
            // 0x1c3748: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3744) {
            ctx->pc = 0x1C3754u;
            goto label_1c3754;
        }
    }
    ctx->pc = 0x1C374Cu;
    // 0x1c374c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1C374Cu;
    {
        const bool branch_taken_0x1c374c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C374Cu;
            // 0x1c3750: 0x24030063  addiu       $v1, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c374c) {
            ctx->pc = 0x1C3800u;
            goto label_1c3800;
        }
    }
    ctx->pc = 0x1C3754u;
label_1c3754:
    // 0x1c3754: 0xc071570  jal         func_1C55C0
    ctx->pc = 0x1C3754u;
    SET_GPR_U32(ctx, 31, 0x1C375Cu);
    ctx->pc = 0x1C55C0u;
    if (runtime->hasFunction(0x1C55C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C55C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C375Cu; }
        if (ctx->pc != 0x1C375Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C55C0_0x1c55c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C375Cu; }
        if (ctx->pc != 0x1C375Cu) { return; }
    }
    ctx->pc = 0x1C375Cu;
label_1c375c:
    // 0x1c375c: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1C375Cu;
    {
        const bool branch_taken_0x1c375c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C3760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C375Cu;
            // 0x1c3760: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c375c) {
            ctx->pc = 0x1C37B8u;
            goto label_1c37b8;
        }
    }
    ctx->pc = 0x1C3764u;
    // 0x1c3764: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c3764u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c3768: 0x90224488  lbu         $v0, 0x4488($at)
    ctx->pc = 0x1c3768u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17544)));
    // 0x1c376c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C376Cu;
    {
        const bool branch_taken_0x1c376c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C3770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C376Cu;
            // 0x1c3770: 0x24020023  addiu       $v0, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c376c) {
            ctx->pc = 0x1C377Cu;
            goto label_1c377c;
        }
    }
    ctx->pc = 0x1C3774u;
    // 0x1c3774: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1C3774u;
    {
        const bool branch_taken_0x1c3774 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3774u;
            // 0x1c3778: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3774) {
            ctx->pc = 0x1C393Cu;
            goto label_1c393c;
        }
    }
    ctx->pc = 0x1C377Cu;
label_1c377c:
    // 0x1c377c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c377cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c3780: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3780u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3784: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c3784u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c3788: 0xa020448d  sb          $zero, 0x448D($at)
    ctx->pc = 0x1c3788u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17549), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c378c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c378cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c3790: 0xc071504  jal         func_1C5410
    ctx->pc = 0x1C3790u;
    SET_GPR_U32(ctx, 31, 0x1C3798u);
    ctx->pc = 0x1C3794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3790u;
            // 0x1c3794: 0xa0204488  sb          $zero, 0x4488($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17544), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5410u;
    if (runtime->hasFunction(0x1C5410u)) {
        auto targetFn = runtime->lookupFunction(0x1C5410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3798u; }
        if (ctx->pc != 0x1C3798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5410_0x1c5410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3798u; }
        if (ctx->pc != 0x1C3798u) { return; }
    }
    ctx->pc = 0x1C3798u;
label_1c3798:
    // 0x1c3798: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c3798u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c379c: 0xc070274  jal         func_1C09D0
    ctx->pc = 0x1C379Cu;
    SET_GPR_U32(ctx, 31, 0x1C37A4u);
    ctx->pc = 0x1C37A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C379Cu;
            // 0x1c37a0: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C09D0u;
    if (runtime->hasFunction(0x1C09D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C09D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C37A4u; }
        if (ctx->pc != 0x1C37A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C09D0_0x1c09d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C37A4u; }
        if (ctx->pc != 0x1C37A4u) { return; }
    }
    ctx->pc = 0x1C37A4u;
label_1c37a4:
    // 0x1c37a4: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1c37a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1c37a8: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1c37a8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c37ac: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c37acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c37b0: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1C37B0u;
    {
        const bool branch_taken_0x1c37b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C37B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C37B0u;
            // 0x1c37b4: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c37b0) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C37B8u;
label_1c37b8:
    // 0x1c37b8: 0x24020034  addiu       $v0, $zero, 0x34
    ctx->pc = 0x1c37b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x1c37bc: 0xa0204476  sb          $zero, 0x4476($at)
    ctx->pc = 0x1c37bcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c37c0: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c37c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c37c4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c37c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c37c8: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c37c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c37cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c37ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c37d0: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c37d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c37d4: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c37d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c37d8: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1C37D8u;
    {
        const bool branch_taken_0x1c37d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C37DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C37D8u;
            // 0x1c37dc: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c37d8) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C37E0u;
label_1c37e0:
    // 0x1c37e0: 0x24020034  addiu       $v0, $zero, 0x34
    ctx->pc = 0x1c37e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x1c37e4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c37e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c37e8: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c37e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c37ec: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1c37ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c37f0: 0xae030034  sw          $v1, 0x34($s0)
    ctx->pc = 0x1c37f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 3));
    // 0x1c37f4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C37F4u;
    {
        const bool branch_taken_0x1c37f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C37F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C37F4u;
            // 0x1c37f8: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c37f4) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C37FCu;
label_1c37fc:
    // 0x1c37fc: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c37fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
label_1c3800:
    // 0x1c3800: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c3800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c3804: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3804u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3808: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c3808u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c380c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c380cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c3810: 0x8e040034  lw          $a0, 0x34($s0)
    ctx->pc = 0x1c3810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c3814: 0x10830012  beq         $a0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C3814u;
    {
        const bool branch_taken_0x1c3814 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3814) {
            ctx->pc = 0x1C3860u;
            goto label_1c3860;
        }
    }
    ctx->pc = 0x1C381Cu;
    // 0x1c381c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c381cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c3820: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C3820u;
    {
        const bool branch_taken_0x1c3820 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C3824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3820u;
            // 0x1c3824: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3820) {
            ctx->pc = 0x1C3858u;
            goto label_1c3858;
        }
    }
    ctx->pc = 0x1C3828u;
    // 0x1c3828: 0x10820008  beq         $a0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C3828u;
    {
        const bool branch_taken_0x1c3828 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c3828) {
            ctx->pc = 0x1C384Cu;
            goto label_1c384c;
        }
    }
    ctx->pc = 0x1C3830u;
    // 0x1c3830: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3834: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3834u;
    {
        const bool branch_taken_0x1c3834 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C3838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3834u;
            // 0x1c3838: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3834) {
            ctx->pc = 0x1C3844u;
            goto label_1c3844;
        }
    }
    ctx->pc = 0x1C383Cu;
    // 0x1c383c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C383Cu;
    {
        const bool branch_taken_0x1c383c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c383c) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C3844u;
label_1c3844:
    // 0x1c3844: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C3844u;
    {
        const bool branch_taken_0x1c3844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3844u;
            // 0x1c3848: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3844) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C384Cu;
label_1c384c:
    // 0x1c384c: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1c384cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1c3850: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C3850u;
    {
        const bool branch_taken_0x1c3850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3850u;
            // 0x1c3854: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3850) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C3858u;
label_1c3858:
    // 0x1c3858: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3858u;
    {
        const bool branch_taken_0x1c3858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C385Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3858u;
            // 0x1c385c: 0xae03002c  sw          $v1, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3858) {
            ctx->pc = 0x1C3868u;
            goto label_1c3868;
        }
    }
    ctx->pc = 0x1C3860u;
label_1c3860:
    // 0x1c3860: 0x24020017  addiu       $v0, $zero, 0x17
    ctx->pc = 0x1c3860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1c3864: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3864u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
label_1c3868:
    // 0x1c3868: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c3868u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c386c: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c386cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c3870: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1C3870u;
    {
        const bool branch_taken_0x1c3870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3870u;
            // 0x1c3874: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3870) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3878u;
label_1c3878:
    // 0x1c3878: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C3878u;
    SET_GPR_U32(ctx, 31, 0x1C3880u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3880u; }
        if (ctx->pc != 0x1C3880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3880u; }
        if (ctx->pc != 0x1C3880u) { return; }
    }
    ctx->pc = 0x1C3880u;
label_1c3880:
    // 0x1c3880: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c3880u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c3884: 0x1043001b  beq         $v0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1C3884u;
    {
        const bool branch_taken_0x1c3884 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3884) {
            ctx->pc = 0x1C38F4u;
            goto label_1c38f4;
        }
    }
    ctx->pc = 0x1C388Cu;
    // 0x1c388c: 0x2403ff02  addiu       $v1, $zero, -0xFE
    ctx->pc = 0x1c388cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c3890: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C3890u;
    {
        const bool branch_taken_0x1c3890 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C3894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3890u;
            // 0x1c3894: 0x2403ff00  addiu       $v1, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3890) {
            ctx->pc = 0x1C38DCu;
            goto label_1c38dc;
        }
    }
    ctx->pc = 0x1C3898u;
    // 0x1c3898: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C3898u;
    {
        const bool branch_taken_0x1c3898 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3898) {
            ctx->pc = 0x1C38C0u;
            goto label_1c38c0;
        }
    }
    ctx->pc = 0x1C38A0u;
    // 0x1c38a0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C38A0u;
    {
        const bool branch_taken_0x1c38a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C38A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C38A0u;
            // 0x1c38a4: 0x24030024  addiu       $v1, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c38a0) {
            ctx->pc = 0x1C38B0u;
            goto label_1c38b0;
        }
    }
    ctx->pc = 0x1C38A8u;
    // 0x1c38a8: 0x1000ffd4  b           . + 4 + (-0x2C << 2)
    ctx->pc = 0x1C38A8u;
    {
        const bool branch_taken_0x1c38a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c38a8) {
            ctx->pc = 0x1C37FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c37fc;
        }
    }
    ctx->pc = 0x1C38B0u;
label_1c38b0:
    // 0x1c38b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c38b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c38b4: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c38b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c38b8: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1C38B8u;
    {
        const bool branch_taken_0x1c38b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C38BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C38B8u;
            // 0x1c38bc: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c38b8) {
            ctx->pc = 0x1C393Cu;
            goto label_1c393c;
        }
    }
    ctx->pc = 0x1C38C0u;
label_1c38c0:
    // 0x1c38c0: 0x24020016  addiu       $v0, $zero, 0x16
    ctx->pc = 0x1c38c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1c38c4: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c38c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c38c8: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c38c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c38cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c38ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c38d0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c38d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c38d4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C38D4u;
    {
        const bool branch_taken_0x1c38d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C38D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C38D4u;
            // 0x1c38d8: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c38d4) {
            ctx->pc = 0x1C38F4u;
            goto label_1c38f4;
        }
    }
    ctx->pc = 0x1C38DCu;
label_1c38dc:
    // 0x1c38dc: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1c38dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1c38e0: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1c38e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c38e4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c38e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c38e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c38e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c38ec: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c38ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c38f0: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c38f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
label_1c38f4:
    // 0x1c38f4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c38f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c38f8: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c38f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c38fc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C38FCu;
    {
        const bool branch_taken_0x1c38fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C38FCu;
            // 0x1c3900: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c38fc) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3904u;
label_1c3904:
    // 0x1c3904: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c3904u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3908: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c3908u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c390c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C390Cu;
    {
        const bool branch_taken_0x1c390c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C390Cu;
            // 0x1c3910: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c390c) {
            ctx->pc = 0x1C3924u;
            goto label_1c3924;
        }
    }
    ctx->pc = 0x1C3914u;
    // 0x1c3914: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C3914u;
    SET_GPR_U32(ctx, 31, 0x1C391Cu);
    ctx->pc = 0x1C3918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3914u;
            // 0x1c3918: 0xa0204476  sb          $zero, 0x4476($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C391Cu; }
        if (ctx->pc != 0x1C391Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C391Cu; }
        if (ctx->pc != 0x1C391Cu) { return; }
    }
    ctx->pc = 0x1C391Cu;
label_1c391c:
    // 0x1c391c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C391Cu;
    {
        const bool branch_taken_0x1c391c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C391Cu;
            // 0x1c3920: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c391c) {
            ctx->pc = 0x1C393Cu;
            goto label_1c393c;
        }
    }
    ctx->pc = 0x1C3924u;
label_1c3924:
    // 0x1c3924: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c3924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c3928:
    // 0x1c3928: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C3928u;
    SET_GPR_U32(ctx, 31, 0x1C3930u);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3930u; }
        if (ctx->pc != 0x1C3930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3930u; }
        if (ctx->pc != 0x1C3930u) { return; }
    }
    ctx->pc = 0x1C3930u;
label_1c3930:
    // 0x1c3930: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C3930u;
    SET_GPR_U32(ctx, 31, 0x1C3938u);
    ctx->pc = 0x1C3934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3930u;
            // 0x1c3934: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3938u; }
        if (ctx->pc != 0x1C3938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3938u; }
        if (ctx->pc != 0x1C3938u) { return; }
    }
    ctx->pc = 0x1C3938u;
label_1c3938:
    // 0x1c3938: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c393c:
    // 0x1c393c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c393cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c3940: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c3940u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c3944: 0x3e00008  jr          $ra
    ctx->pc = 0x1C3944u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C3948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3944u;
            // 0x1c3948: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C35D8u: goto label_1c35d8;
            case 0x1C35F4u: goto label_1c35f4;
            case 0x1C35FCu: goto label_1c35fc;
            case 0x1C3604u: goto label_1c3604;
            case 0x1C3648u: goto label_1c3648;
            case 0x1C3664u: goto label_1c3664;
            case 0x1C3680u: goto label_1c3680;
            case 0x1C369Cu: goto label_1c369c;
            case 0x1C36A8u: goto label_1c36a8;
            case 0x1C36C0u: goto label_1c36c0;
            case 0x1C36C8u: goto label_1c36c8;
            case 0x1C370Cu: goto label_1c370c;
            case 0x1C3718u: goto label_1c3718;
            case 0x1C371Cu: goto label_1c371c;
            case 0x1C3724u: goto label_1c3724;
            case 0x1C372Cu: goto label_1c372c;
            case 0x1C3754u: goto label_1c3754;
            case 0x1C375Cu: goto label_1c375c;
            case 0x1C377Cu: goto label_1c377c;
            case 0x1C3798u: goto label_1c3798;
            case 0x1C37A4u: goto label_1c37a4;
            case 0x1C37B8u: goto label_1c37b8;
            case 0x1C37E0u: goto label_1c37e0;
            case 0x1C37FCu: goto label_1c37fc;
            case 0x1C3800u: goto label_1c3800;
            case 0x1C3844u: goto label_1c3844;
            case 0x1C384Cu: goto label_1c384c;
            case 0x1C3858u: goto label_1c3858;
            case 0x1C3860u: goto label_1c3860;
            case 0x1C3868u: goto label_1c3868;
            case 0x1C3878u: goto label_1c3878;
            case 0x1C3880u: goto label_1c3880;
            case 0x1C38B0u: goto label_1c38b0;
            case 0x1C38C0u: goto label_1c38c0;
            case 0x1C38DCu: goto label_1c38dc;
            case 0x1C38F4u: goto label_1c38f4;
            case 0x1C3904u: goto label_1c3904;
            case 0x1C391Cu: goto label_1c391c;
            case 0x1C3924u: goto label_1c3924;
            case 0x1C3928u: goto label_1c3928;
            case 0x1C3930u: goto label_1c3930;
            case 0x1C3938u: goto label_1c3938;
            case 0x1C393Cu: goto label_1c393c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C394Cu;
    // 0x1c394c: 0x0  nop
    ctx->pc = 0x1c394cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
