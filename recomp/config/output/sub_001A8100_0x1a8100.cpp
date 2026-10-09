#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8100
// Address: 0x1a8100 - 0x1a81e0
void sub_001A8100_0x1a8100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8100_0x1a8100");
#endif

    ctx->pc = 0x1a8100u;

    // 0x1a8100: 0x47602  srl         $t6, $a0, 24
    ctx->pc = 0x1a8100u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x1a8104: 0x31cc0001  andi        $t4, $t6, 0x1
    ctx->pc = 0x1a8104u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)1);
    // 0x1a8108: 0x11800002  beqz        $t4, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A8108u;
    {
        const bool branch_taken_0x1a8108 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A810Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8108u;
            // 0x1a810c: 0x240d0004  addiu       $t5, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8108) {
            ctx->pc = 0x1A8114u;
            goto label_1a8114;
        }
    }
    ctx->pc = 0x1A8110u;
    // 0x1a8110: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x1a8110u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
label_1a8114:
    // 0x1a8114: 0x31cb0002  andi        $t3, $t6, 0x2
    ctx->pc = 0x1a8114u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)2);
    // 0x1a8118: 0x11600002  beqz        $t3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A8118u;
    {
        const bool branch_taken_0x1a8118 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A811Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8118u;
            // 0x1a811c: 0x31ca0004  andi        $t2, $t6, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8118) {
            ctx->pc = 0x1A8124u;
            goto label_1a8124;
        }
    }
    ctx->pc = 0x1A8120u;
    // 0x1a8120: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x1a8120u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
label_1a8124:
    // 0x1a8124: 0x11400002  beqz        $t2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A8124u;
    {
        const bool branch_taken_0x1a8124 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8124u;
            // 0x1a8128: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8124) {
            ctx->pc = 0x1A8130u;
            goto label_1a8130;
        }
    }
    ctx->pc = 0x1A812Cu;
    // 0x1a812c: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x1a812cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
label_1a8130:
    // 0x1a8130: 0x8c290a60  lw          $t1, 0xA60($at)
    ctx->pc = 0x1a8130u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8134: 0x12d1021  addu        $v0, $t1, $t5
    ctx->pc = 0x1a8134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 13)));
    // 0x1a8138: 0x28420200  slti        $v0, $v0, 0x200
    ctx->pc = 0x1a8138u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x1a813c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A813Cu;
    {
        const bool branch_taken_0x1a813c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A8140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A813Cu;
            // 0x1a8140: 0x3c02002b  lui         $v0, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a813c) {
            ctx->pc = 0x1A814Cu;
            goto label_1a814c;
        }
    }
    ctx->pc = 0x1A8144u;
    // 0x1a8144: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1A8144u;
    {
        const bool branch_taken_0x1a8144 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8144u;
            // 0x1a8148: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8144) {
            ctx->pc = 0x1A81CCu;
            goto label_1a81cc;
        }
    }
    ctx->pc = 0x1A814Cu;
label_1a814c:
    // 0x1a814c: 0x41c02  srl         $v1, $a0, 16
    ctx->pc = 0x1a814cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x1a8150: 0x24420cc0  addiu       $v0, $v0, 0xCC0
    ctx->pc = 0x1a8150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
    // 0x1a8154: 0x494821  addu        $t1, $v0, $t1
    ctx->pc = 0x1a8154u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1a8158: 0xa12e0000  sb          $t6, 0x0($t1)
    ctx->pc = 0x1a8158u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 14));
    // 0x1a815c: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x1a815cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1a8160: 0xa1230001  sb          $v1, 0x1($t1)
    ctx->pc = 0x1a8160u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a8164: 0xa1220002  sb          $v0, 0x2($t1)
    ctx->pc = 0x1a8164u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a8168: 0xa1240003  sb          $a0, 0x3($t1)
    ctx->pc = 0x1a8168u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a816c: 0x11800003  beqz        $t4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A816Cu;
    {
        const bool branch_taken_0x1a816c = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A816Cu;
            // 0x1a8170: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a816c) {
            ctx->pc = 0x1A817Cu;
            goto label_1a817c;
        }
    }
    ctx->pc = 0x1A8174u;
    // 0x1a8174: 0xa1250000  sb          $a1, 0x0($t1)
    ctx->pc = 0x1a8174u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a8178: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1a8178u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
label_1a817c:
    // 0x1a817c: 0x11600003  beqz        $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A817Cu;
    {
        const bool branch_taken_0x1a817c = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a817c) {
            ctx->pc = 0x1A818Cu;
            goto label_1a818c;
        }
    }
    ctx->pc = 0x1A8184u;
    // 0x1a8184: 0xa1260000  sb          $a2, 0x0($t1)
    ctx->pc = 0x1a8184u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a8188: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1a8188u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
label_1a818c:
    // 0x1a818c: 0x11400005  beqz        $t2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A818Cu;
    {
        const bool branch_taken_0x1a818c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A818Cu;
            // 0x1a8190: 0x30e3ffff  andi        $v1, $a3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a818c) {
            ctx->pc = 0x1A81A4u;
            goto label_1a81a4;
        }
    }
    ctx->pc = 0x1A8194u;
    // 0x1a8194: 0x31203  sra         $v0, $v1, 8
    ctx->pc = 0x1a8194u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1a8198: 0xa1220000  sb          $v0, 0x0($t1)
    ctx->pc = 0x1a8198u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a819c: 0xa1230001  sb          $v1, 0x1($t1)
    ctx->pc = 0x1a819cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a81a0: 0x25290002  addiu       $t1, $t1, 0x2
    ctx->pc = 0x1a81a0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 2));
label_1a81a4:
    // 0x1a81a4: 0xa1280000  sb          $t0, 0x0($t1)
    ctx->pc = 0x1a81a4u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1a81a8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a81a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a81ac: 0x8c240a60  lw          $a0, 0xA60($at)
    ctx->pc = 0x1a81acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a81b0: 0x25a50001  addiu       $a1, $t5, 0x1
    ctx->pc = 0x1a81b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x1a81b4: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1a81b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a81b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a81b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a81bc: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1a81bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1a81c0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a81c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a81c4: 0xac240a60  sw          $a0, 0xA60($at)
    ctx->pc = 0x1a81c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 4));
    // 0x1a81c8: 0xa1230001  sb          $v1, 0x1($t1)
    ctx->pc = 0x1a81c8u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 1), (uint8_t)GPR_U32(ctx, 3));
label_1a81cc:
    // 0x1a81cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A81CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A8114u: goto label_1a8114;
            case 0x1A8124u: goto label_1a8124;
            case 0x1A8130u: goto label_1a8130;
            case 0x1A814Cu: goto label_1a814c;
            case 0x1A817Cu: goto label_1a817c;
            case 0x1A818Cu: goto label_1a818c;
            case 0x1A81A4u: goto label_1a81a4;
            case 0x1A81CCu: goto label_1a81cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A81D4u;
    // 0x1a81d4: 0x0  nop
    ctx->pc = 0x1a81d4u;
    // NOP
    // 0x1a81d8: 0x0  nop
    ctx->pc = 0x1a81d8u;
    // NOP
    // 0x1a81dc: 0x0  nop
    ctx->pc = 0x1a81dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
