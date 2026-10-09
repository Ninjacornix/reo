#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B248
// Address: 0x11b248 - 0x11b828
void sub_0011B248_0x11b248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B248_0x11b248");
#endif

    switch (ctx->pc) {
        case 0x11b294u: goto label_11b294;
        case 0x11b2b4u: goto label_11b2b4;
        case 0x11b2d0u: goto label_11b2d0;
        case 0x11b324u: goto label_11b324;
        case 0x11b348u: goto label_11b348;
        case 0x11b3a8u: goto label_11b3a8;
        case 0x11b3d0u: goto label_11b3d0;
        case 0x11b3f8u: goto label_11b3f8;
        case 0x11b408u: goto label_11b408;
        case 0x11b410u: goto label_11b410;
        case 0x11b424u: goto label_11b424;
        case 0x11b434u: goto label_11b434;
        case 0x11b444u: goto label_11b444;
        case 0x11b44cu: goto label_11b44c;
        case 0x11b4bcu: goto label_11b4bc;
        case 0x11b4d4u: goto label_11b4d4;
        case 0x11b4f8u: goto label_11b4f8;
        case 0x11b558u: goto label_11b558;
        case 0x11b5a4u: goto label_11b5a4;
        case 0x11b5e0u: goto label_11b5e0;
        case 0x11b5f0u: goto label_11b5f0;
        case 0x11b5f8u: goto label_11b5f8;
        case 0x11b60cu: goto label_11b60c;
        case 0x11b61cu: goto label_11b61c;
        case 0x11b62cu: goto label_11b62c;
        case 0x11b634u: goto label_11b634;
        case 0x11b6a4u: goto label_11b6a4;
        case 0x11b6bcu: goto label_11b6bc;
        case 0x11b6e8u: goto label_11b6e8;
        case 0x11b74cu: goto label_11b74c;
        case 0x11b768u: goto label_11b768;
        case 0x11b7a4u: goto label_11b7a4;
        case 0x11b7b4u: goto label_11b7b4;
        case 0x11b7bcu: goto label_11b7bc;
        case 0x11b7d0u: goto label_11b7d0;
        case 0x11b7e0u: goto label_11b7e0;
        case 0x11b7f0u: goto label_11b7f0;
        case 0x11b7f8u: goto label_11b7f8;
        default: break;
    }

    ctx->pc = 0x11b248u;

    // 0x11b248: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x11b248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x11b24c: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b24cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b250: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x11b250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x11b254: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11b254u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b258: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11b258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11b25c: 0x100f02d  daddu       $fp, $t0, $zero
    ctx->pc = 0x11b25cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b260: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b264: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x11b264u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b268: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b26c: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x11b26cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b270: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b274: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11b274u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b278: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b27c: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x11b27cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b280: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x11b280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x11b284: 0x24040017  addiu       $a0, $zero, 0x17
    ctx->pc = 0x11b284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x11b288: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b28c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B28Cu;
    SET_GPR_U32(ctx, 31, 0x11B294u);
    ctx->pc = 0x11B290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B28Cu;
            // 0x11b290: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B294u; }
        if (ctx->pc != 0x11B294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B294u; }
        if (ctx->pc != 0x11B294u) { return; }
    }
    ctx->pc = 0x11B294u;
label_11b294:
    // 0x11b294: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11b294u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11b298: 0x2452ca40  addiu       $s2, $v0, -0x35C0
    ctx->pc = 0x11b298u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953536));
    // 0x11b29c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11b29cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11b2a0: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11b2a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11b2a4: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B2A4u;
    {
        const bool branch_taken_0x11b2a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b2a4) {
            ctx->pc = 0x11B2A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B2A4u;
            // 0x11b2a8: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B2B8u;
            goto label_11b2b8;
        }
    }
    ctx->pc = 0x11B2ACu;
    // 0x11b2ac: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11B2ACu;
    SET_GPR_U32(ctx, 31, 0x11B2B4u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B2B4u; }
        if (ctx->pc != 0x11B2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B2B4u; }
        if (ctx->pc != 0x11B2B4u) { return; }
    }
    ctx->pc = 0x11B2B4u;
label_11b2b4:
    // 0x11b2b4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11b2b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11b2b8:
    // 0x11b2b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b2b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b2bc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b2c0: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x11B2C0u;
    {
        const bool branch_taken_0x11b2c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B2C0u;
            // 0x11b2c4: 0xa242000c  sb          $v0, 0xC($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b2c0) {
            ctx->pc = 0x11B2FCu;
            goto label_11b2fc;
        }
    }
    ctx->pc = 0x11B2C8u;
    // 0x11b2c8: 0x2e060401  sltiu       $a2, $s0, 0x401
    ctx->pc = 0x11b2c8u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
    // 0x11b2cc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b2ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11b2d0:
    // 0x11b2d0: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b2d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b2d4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11B2D4u;
    {
        const bool branch_taken_0x11b2d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B2D4u;
            // 0x11b2d8: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b2d4) {
            ctx->pc = 0x11B300u;
            goto label_11b300;
        }
    }
    ctx->pc = 0x11B2DCu;
    // 0x11b2dc: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11b2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11b2e0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b2e0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b2e4: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x11b2e4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b2e8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b2e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b2ec: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B2ECu;
    {
        const bool branch_taken_0x11b2ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b2ec) {
            ctx->pc = 0x11B2F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B2ECu;
            // 0x11b2f0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B2D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b2d0;
        }
    }
    ctx->pc = 0x11B2F4u;
    // 0x11b2f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11B2F4u;
    {
        const bool branch_taken_0x11b2f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B2F4u;
            // 0x11b2f8: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b2f4) {
            ctx->pc = 0x11B304u;
            goto label_11b304;
        }
    }
    ctx->pc = 0x11B2FCu;
label_11b2fc:
    // 0x11b2fc: 0x2e060401  sltiu       $a2, $s0, 0x401
    ctx->pc = 0x11b2fcu;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
label_11b300:
    // 0x11b300: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11b304:
    // 0x11b304: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B304u;
    {
        const bool branch_taken_0x11b304 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b304) {
            ctx->pc = 0x11B308u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B304u;
            // 0x11b308: 0xa240040b  sb          $zero, 0x40B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B30Cu;
            goto label_11b30c;
        }
    }
    ctx->pc = 0x11B30Cu;
label_11b30c:
    // 0x11b30c: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x11B30Cu;
    {
        const bool branch_taken_0x11b30c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B30Cu;
            // 0x11b310: 0x2ec20401  sltiu       $v0, $s6, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b30c) {
            ctx->pc = 0x11B31Cu;
            goto label_11b31c;
        }
    }
    ctx->pc = 0x11B314u;
    // 0x11b314: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B314u;
    {
        const bool branch_taken_0x11b314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b314) {
            ctx->pc = 0x11B32Cu;
            goto label_11b32c;
        }
    }
    ctx->pc = 0x11B31Cu;
label_11b31c:
    // 0x11b31c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B31Cu;
    SET_GPR_U32(ctx, 31, 0x11B324u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B324u; }
        if (ctx->pc != 0x11B324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B324u; }
        if (ctx->pc != 0x11B324u) { return; }
    }
    ctx->pc = 0x11B324u;
label_11b324:
    // 0x11b324: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x11B324u;
    {
        const bool branch_taken_0x11b324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B324u;
            // 0x11b328: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b324) {
            ctx->pc = 0x11B450u;
            goto label_11b450;
        }
    }
    ctx->pc = 0x11B32Cu;
label_11b32c:
    // 0x11b32c: 0x12000010  beqz        $s0, . + 4 + (0x10 << 2)
    ctx->pc = 0x11B32Cu;
    {
        const bool branch_taken_0x11b32c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B32Cu;
            // 0x11b330: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b32c) {
            ctx->pc = 0x11B370u;
            goto label_11b370;
        }
    }
    ctx->pc = 0x11B334u;
    // 0x11b334: 0x2646040c  addiu       $a2, $s2, 0x40C
    ctx->pc = 0x11b334u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 1036));
    // 0x11b338: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b338u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b33c: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b33cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b340: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x11b340u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11b344: 0x0  nop
    ctx->pc = 0x11b344u;
    // NOP
label_11b348:
    // 0x11b348: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x11b348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x11b34c: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11b34cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11b350: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b350u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b354: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b354u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11b358: 0xb0102b  sltu        $v0, $a1, $s0
    ctx->pc = 0x11b358u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x11b35c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11b35cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b360: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11B360u;
    {
        const bool branch_taken_0x11b360 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b360) {
            ctx->pc = 0x11B348u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b348;
        }
    }
    ctx->pc = 0x11B368u;
    // 0x11b368: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11B368u;
    {
        const bool branch_taken_0x11b368 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B368u;
            // 0x11b36c: 0xae500810  sw          $s0, 0x810($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 2064), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b368) {
            ctx->pc = 0x11B380u;
            goto label_11b380;
        }
    }
    ctx->pc = 0x11B370u;
label_11b370:
    // 0x11b370: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b370u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b374: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b374u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b378: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x11b378u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11b37c: 0xae500810  sw          $s0, 0x810($s2)
    ctx->pc = 0x11b37cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2064), GPR_U32(ctx, 16));
label_11b380:
    // 0x11b380: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11b380u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b384: 0xae57080c  sw          $s7, 0x80C($s2)
    ctx->pc = 0x11b384u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2060), GPR_U32(ctx, 23));
    // 0x11b388: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b388u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b38c: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11b38cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11b390: 0x2634d680  addiu       $s4, $s1, -0x2980
    ctx->pc = 0x11b390u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 4294956672));
    // 0x11b394: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11b394u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11b398: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b398u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b39c: 0x2450ca40  addiu       $s0, $v0, -0x35C0
    ctx->pc = 0x11b39cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953536));
    // 0x11b3a0: 0xc045188  jal         func_114620
    ctx->pc = 0x11B3A0u;
    SET_GPR_U32(ctx, 31, 0x11B3A8u);
    ctx->pc = 0x11B3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B3A0u;
            // 0x11b3a4: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3A8u; }
        if (ctx->pc != 0x11B3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3A8u; }
        if (ctx->pc != 0x11B3A8u) { return; }
    }
    ctx->pc = 0x11B3A8u;
label_11b3a8:
    // 0x11b3a8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11b3a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b3ac: 0xae560818  sw          $s6, 0x818($s2)
    ctx->pc = 0x11b3acu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2072), GPR_U32(ctx, 22));
    // 0x11b3b0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11b3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b3b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11b3b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b3b8: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11b3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11b3bc: 0x2405081c  addiu       $a1, $zero, 0x81C
    ctx->pc = 0x11b3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2076));
    // 0x11b3c0: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11b3c0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11b3c4: 0xae5e0814  sw          $fp, 0x814($s2)
    ctx->pc = 0x11b3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2068), GPR_U32(ctx, 30));
    // 0x11b3c8: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11B3C8u;
    SET_GPR_U32(ctx, 31, 0x11B3D0u);
    ctx->pc = 0x11B3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B3C8u;
            // 0x11b3cc: 0xae510000  sw          $s1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3D0u; }
        if (ctx->pc != 0x11B3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3D0u; }
        if (ctx->pc != 0x11B3D0u) { return; }
    }
    ctx->pc = 0x11B3D0u;
label_11b3d0:
    // 0x11b3d0: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11b3d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11b3d4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11b3d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b3d8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b3dc: 0x24050017  addiu       $a1, $zero, 0x17
    ctx->pc = 0x11b3dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x11b3e0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b3e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b3e4: 0x2408081c  addiu       $t0, $zero, 0x81C
    ctx->pc = 0x11b3e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2076));
    // 0x11b3e8: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x11b3e8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b3ec: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b3ecu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b3f0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B3F0u;
    SET_GPR_U32(ctx, 31, 0x11B3F8u);
    ctx->pc = 0x11B3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B3F0u;
            // 0x11b3f4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3F8u; }
        if (ctx->pc != 0x11B3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B3F8u; }
        if (ctx->pc != 0x11B3F8u) { return; }
    }
    ctx->pc = 0x11B3F8u;
label_11b3f8:
    // 0x11b3f8: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B3F8u;
    {
        const bool branch_taken_0x11b3f8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B3F8u;
            // 0x11b3fc: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b3f8) {
            ctx->pc = 0x11B418u;
            goto label_11b418;
        }
    }
    ctx->pc = 0x11B400u;
    // 0x11b400: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B400u;
    SET_GPR_U32(ctx, 31, 0x11B408u);
    ctx->pc = 0x11B404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B400u;
            // 0x11b404: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B408u; }
        if (ctx->pc != 0x11B408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B408u; }
        if (ctx->pc != 0x11B408u) { return; }
    }
    ctx->pc = 0x11B408u;
label_11b408:
    // 0x11b408: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B408u;
    SET_GPR_U32(ctx, 31, 0x11B410u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B410u; }
        if (ctx->pc != 0x11B410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B410u; }
        if (ctx->pc != 0x11B410u) { return; }
    }
    ctx->pc = 0x11B410u;
label_11b410:
    // 0x11b410: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11B410u;
    {
        const bool branch_taken_0x11b410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B410u;
            // 0x11b414: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b410) {
            ctx->pc = 0x11B450u;
            goto label_11b450;
        }
    }
    ctx->pc = 0x11B418u;
label_11b418:
    // 0x11b418: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x11b418u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x11b41c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B41Cu;
    SET_GPR_U32(ctx, 31, 0x11B424u);
    ctx->pc = 0x11B420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B41Cu;
            // 0x11b420: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B424u; }
        if (ctx->pc != 0x11B424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B424u; }
        if (ctx->pc != 0x11B424u) { return; }
    }
    ctx->pc = 0x11B424u;
label_11b424:
    // 0x11b424: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B424u;
    {
        const bool branch_taken_0x11b424 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b424) {
            ctx->pc = 0x11B43Cu;
            goto label_11b43c;
        }
    }
    ctx->pc = 0x11B42Cu;
    // 0x11b42c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B42Cu;
    SET_GPR_U32(ctx, 31, 0x11B434u);
    ctx->pc = 0x11B430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B42Cu;
            // 0x11b430: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B434u; }
        if (ctx->pc != 0x11B434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B434u; }
        if (ctx->pc != 0x11B434u) { return; }
    }
    ctx->pc = 0x11B434u;
label_11b434:
    // 0x11b434: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B434u;
    {
        const bool branch_taken_0x11b434 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B434u;
            // 0x11b438: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b434) {
            ctx->pc = 0x11B450u;
            goto label_11b450;
        }
    }
    ctx->pc = 0x11B43Cu;
label_11b43c:
    // 0x11b43c: 0xc045198  jal         func_114660
    ctx->pc = 0x11B43Cu;
    SET_GPR_U32(ctx, 31, 0x11B444u);
    ctx->pc = 0x11B440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B43Cu;
            // 0x11b440: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B444u; }
        if (ctx->pc != 0x11B444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B444u; }
        if (ctx->pc != 0x11B444u) { return; }
    }
    ctx->pc = 0x11B444u;
label_11b444:
    // 0x11b444: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B444u;
    SET_GPR_U32(ctx, 31, 0x11B44Cu);
    ctx->pc = 0x11B448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B444u;
            // 0x11b448: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B44Cu; }
        if (ctx->pc != 0x11B44Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B44Cu; }
        if (ctx->pc != 0x11B44Cu) { return; }
    }
    ctx->pc = 0x11B44Cu;
label_11b44c:
    // 0x11b44c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11b44cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11b450:
    // 0x11b450: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x11b450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x11b454: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x11b454u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11b458: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11b458u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b45c: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b45cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b460: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b460u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b464: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b464u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b468: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b468u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b46c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b46cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b470: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b470u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b474: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b474u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b478: 0x3e00008  jr          $ra
    ctx->pc = 0x11B478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B478u;
            // 0x11b47c: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B294u: goto label_11b294;
            case 0x11B2B4u: goto label_11b2b4;
            case 0x11B2B8u: goto label_11b2b8;
            case 0x11B2D0u: goto label_11b2d0;
            case 0x11B2FCu: goto label_11b2fc;
            case 0x11B300u: goto label_11b300;
            case 0x11B304u: goto label_11b304;
            case 0x11B30Cu: goto label_11b30c;
            case 0x11B31Cu: goto label_11b31c;
            case 0x11B324u: goto label_11b324;
            case 0x11B32Cu: goto label_11b32c;
            case 0x11B348u: goto label_11b348;
            case 0x11B370u: goto label_11b370;
            case 0x11B380u: goto label_11b380;
            case 0x11B3A8u: goto label_11b3a8;
            case 0x11B3D0u: goto label_11b3d0;
            case 0x11B3F8u: goto label_11b3f8;
            case 0x11B408u: goto label_11b408;
            case 0x11B410u: goto label_11b410;
            case 0x11B418u: goto label_11b418;
            case 0x11B424u: goto label_11b424;
            case 0x11B434u: goto label_11b434;
            case 0x11B43Cu: goto label_11b43c;
            case 0x11B444u: goto label_11b444;
            case 0x11B44Cu: goto label_11b44c;
            case 0x11B450u: goto label_11b450;
            case 0x11B4BCu: goto label_11b4bc;
            case 0x11B4D4u: goto label_11b4d4;
            case 0x11B4D8u: goto label_11b4d8;
            case 0x11B4F8u: goto label_11b4f8;
            case 0x11B524u: goto label_11b524;
            case 0x11B530u: goto label_11b530;
            case 0x11B534u: goto label_11b534;
            case 0x11B53Cu: goto label_11b53c;
            case 0x11B558u: goto label_11b558;
            case 0x11B57Cu: goto label_11b57c;
            case 0x11B588u: goto label_11b588;
            case 0x11B5A4u: goto label_11b5a4;
            case 0x11B5E0u: goto label_11b5e0;
            case 0x11B5F0u: goto label_11b5f0;
            case 0x11B5F8u: goto label_11b5f8;
            case 0x11B600u: goto label_11b600;
            case 0x11B60Cu: goto label_11b60c;
            case 0x11B61Cu: goto label_11b61c;
            case 0x11B624u: goto label_11b624;
            case 0x11B62Cu: goto label_11b62c;
            case 0x11B634u: goto label_11b634;
            case 0x11B638u: goto label_11b638;
            case 0x11B6A4u: goto label_11b6a4;
            case 0x11B6BCu: goto label_11b6bc;
            case 0x11B6C0u: goto label_11b6c0;
            case 0x11B6E8u: goto label_11b6e8;
            case 0x11B714u: goto label_11b714;
            case 0x11B724u: goto label_11b724;
            case 0x11B728u: goto label_11b728;
            case 0x11B730u: goto label_11b730;
            case 0x11B74Cu: goto label_11b74c;
            case 0x11B768u: goto label_11b768;
            case 0x11B7A4u: goto label_11b7a4;
            case 0x11B7B4u: goto label_11b7b4;
            case 0x11B7BCu: goto label_11b7bc;
            case 0x11B7C4u: goto label_11b7c4;
            case 0x11B7D0u: goto label_11b7d0;
            case 0x11B7E0u: goto label_11b7e0;
            case 0x11B7E8u: goto label_11b7e8;
            case 0x11B7F0u: goto label_11b7f0;
            case 0x11B7F8u: goto label_11b7f8;
            case 0x11B7FCu: goto label_11b7fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B480u;
    // 0x11b480: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x11b480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x11b484: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b488: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b48c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11b48cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b490: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b490u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b494: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11b494u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b498: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b49c: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x11b49cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11b4a0: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x11b4a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x11b4a4: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b4a4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b4a8: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b4ac: 0x26d2ca40  addiu       $s2, $s6, -0x35C0
    ctx->pc = 0x11b4acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11b4b0: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b4b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b4b4: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B4B4u;
    SET_GPR_U32(ctx, 31, 0x11B4BCu);
    ctx->pc = 0x11B4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4B4u;
            // 0x11b4b8: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4BCu; }
        if (ctx->pc != 0x11B4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4BCu; }
        if (ctx->pc != 0x11B4BCu) { return; }
    }
    ctx->pc = 0x11B4BCu;
label_11b4bc:
    // 0x11b4bc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11b4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11b4c0: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11b4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11b4c4: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B4C4u;
    {
        const bool branch_taken_0x11b4c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b4c4) {
            ctx->pc = 0x11B4C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4C4u;
            // 0x11b4c8: 0x92020000  lbu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B4D8u;
            goto label_11b4d8;
        }
    }
    ctx->pc = 0x11B4CCu;
    // 0x11b4cc: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11B4CCu;
    SET_GPR_U32(ctx, 31, 0x11B4D4u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4D4u; }
        if (ctx->pc != 0x11B4D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4D4u; }
        if (ctx->pc != 0x11B4D4u) { return; }
    }
    ctx->pc = 0x11B4D4u;
label_11b4d4:
    // 0x11b4d4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x11b4d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_11b4d8:
    // 0x11b4d8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b4d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b4dc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b4e0: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x11B4E0u;
    {
        const bool branch_taken_0x11b4e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4E0u;
            // 0x11b4e4: 0xa242000c  sb          $v0, 0xC($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b4e0) {
            ctx->pc = 0x11B524u;
            goto label_11b524;
        }
    }
    ctx->pc = 0x11B4E8u;
    // 0x11b4e8: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b4e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b4ec: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b4ecu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b4f0: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b4f0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11b4f4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11b4f8:
    // 0x11b4f8: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b4f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b4fc: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11B4FCu;
    {
        const bool branch_taken_0x11b4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4FCu;
            // 0x11b500: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b4fc) {
            ctx->pc = 0x11B530u;
            goto label_11b530;
        }
    }
    ctx->pc = 0x11B504u;
    // 0x11b504: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11b504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11b508: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b508u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b50c: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x11b50cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b510: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b510u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b514: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B514u;
    {
        const bool branch_taken_0x11b514 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b514) {
            ctx->pc = 0x11B518u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B514u;
            // 0x11b518: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B4F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b4f8;
        }
    }
    ctx->pc = 0x11B51Cu;
    // 0x11b51c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11B51Cu;
    {
        const bool branch_taken_0x11b51c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B51Cu;
            // 0x11b520: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b51c) {
            ctx->pc = 0x11B534u;
            goto label_11b534;
        }
    }
    ctx->pc = 0x11B524u;
label_11b524:
    // 0x11b524: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b524u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b528: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b528u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b52c: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b52cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11b530:
    // 0x11b530: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11b534:
    // 0x11b534: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B534u;
    {
        const bool branch_taken_0x11b534 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b534) {
            ctx->pc = 0x11B538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B534u;
            // 0x11b538: 0xa240040b  sb          $zero, 0x40B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B53Cu;
            goto label_11b53c;
        }
    }
    ctx->pc = 0x11B53Cu;
label_11b53c:
    // 0x11b53c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11b53cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11b540: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b540u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b544: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b544u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b548: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x11B548u;
    {
        const bool branch_taken_0x11b548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B548u;
            // 0x11b54c: 0xa242040c  sb          $v0, 0x40C($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1036), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b548) {
            ctx->pc = 0x11B57Cu;
            goto label_11b57c;
        }
    }
    ctx->pc = 0x11B550u;
    // 0x11b550: 0x2646040c  addiu       $a2, $s2, 0x40C
    ctx->pc = 0x11b550u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 1036));
    // 0x11b554: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b554u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11b558:
    // 0x11b558: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b558u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b55c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B55Cu;
    {
        const bool branch_taken_0x11b55c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B55Cu;
            // 0x11b560: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b55c) {
            ctx->pc = 0x11B57Cu;
            goto label_11b57c;
        }
    }
    ctx->pc = 0x11B564u;
    // 0x11b564: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11b564u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11b568: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b568u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b56c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11b56cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b570: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b570u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b574: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B574u;
    {
        const bool branch_taken_0x11b574 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b574) {
            ctx->pc = 0x11B578u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B574u;
            // 0x11b578: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B558u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b558;
        }
    }
    ctx->pc = 0x11B57Cu;
label_11b57c:
    // 0x11b57c: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b57cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x11b580: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B580u;
    {
        const bool branch_taken_0x11b580 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b580) {
            ctx->pc = 0x11B584u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B580u;
            // 0x11b584: 0xa240080b  sb          $zero, 0x80B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 2059), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B588u;
            goto label_11b588;
        }
    }
    ctx->pc = 0x11B588u;
label_11b588:
    // 0x11b588: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11b588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b58c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b58cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b590: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11b590u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11b594: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b594u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b598: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x11b598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x11b59c: 0xc045188  jal         func_114620
    ctx->pc = 0x11B59Cu;
    SET_GPR_U32(ctx, 31, 0x11B5A4u);
    ctx->pc = 0x11B5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B59Cu;
            // 0x11b5a0: 0x2690d680  addiu       $s0, $s4, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5A4u; }
        if (ctx->pc != 0x11B5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5A4u; }
        if (ctx->pc != 0x11B5A4u) { return; }
    }
    ctx->pc = 0x11B5A4u;
label_11b5a4:
    // 0x11b5a4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11b5a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5a8: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11b5a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11b5ac: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11b5acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b5b0: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11b5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11b5b4: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11b5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11b5b8: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11b5b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11b5bc: 0x26c7ca40  addiu       $a3, $s6, -0x35C0
    ctx->pc = 0x11b5bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11b5c0: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x11b5c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x11b5c4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b5c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b5c8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b5c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5cc: 0x2408080c  addiu       $t0, $zero, 0x80C
    ctx->pc = 0x11b5ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11b5d0: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11b5d0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5d4: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b5d4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b5d8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B5D8u;
    SET_GPR_U32(ctx, 31, 0x11B5E0u);
    ctx->pc = 0x11B5DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5D8u;
            // 0x11b5dc: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5E0u; }
        if (ctx->pc != 0x11B5E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5E0u; }
        if (ctx->pc != 0x11B5E0u) { return; }
    }
    ctx->pc = 0x11B5E0u;
label_11b5e0:
    // 0x11b5e0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B5E0u;
    {
        const bool branch_taken_0x11b5e0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5E0u;
            // 0x11b5e4: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b5e0) {
            ctx->pc = 0x11B600u;
            goto label_11b600;
        }
    }
    ctx->pc = 0x11B5E8u;
    // 0x11b5e8: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B5E8u;
    SET_GPR_U32(ctx, 31, 0x11B5F0u);
    ctx->pc = 0x11B5ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5E8u;
            // 0x11b5ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F0u; }
        if (ctx->pc != 0x11B5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F0u; }
        if (ctx->pc != 0x11B5F0u) { return; }
    }
    ctx->pc = 0x11B5F0u;
label_11b5f0:
    // 0x11b5f0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B5F0u;
    SET_GPR_U32(ctx, 31, 0x11B5F8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F8u; }
        if (ctx->pc != 0x11B5F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F8u; }
        if (ctx->pc != 0x11B5F8u) { return; }
    }
    ctx->pc = 0x11B5F8u;
label_11b5f8:
    // 0x11b5f8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11B5F8u;
    {
        const bool branch_taken_0x11b5f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B5FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5F8u;
            // 0x11b5fc: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b5f8) {
            ctx->pc = 0x11B638u;
            goto label_11b638;
        }
    }
    ctx->pc = 0x11B600u;
label_11b600:
    // 0x11b600: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x11b600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11b604: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B604u;
    SET_GPR_U32(ctx, 31, 0x11B60Cu);
    ctx->pc = 0x11B608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B604u;
            // 0x11b608: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B60Cu; }
        if (ctx->pc != 0x11B60Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B60Cu; }
        if (ctx->pc != 0x11B60Cu) { return; }
    }
    ctx->pc = 0x11B60Cu;
label_11b60c:
    // 0x11b60c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B60Cu;
    {
        const bool branch_taken_0x11b60c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b60c) {
            ctx->pc = 0x11B624u;
            goto label_11b624;
        }
    }
    ctx->pc = 0x11B614u;
    // 0x11b614: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B614u;
    SET_GPR_U32(ctx, 31, 0x11B61Cu);
    ctx->pc = 0x11B618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B614u;
            // 0x11b618: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B61Cu; }
        if (ctx->pc != 0x11B61Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B61Cu; }
        if (ctx->pc != 0x11B61Cu) { return; }
    }
    ctx->pc = 0x11B61Cu;
label_11b61c:
    // 0x11b61c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B61Cu;
    {
        const bool branch_taken_0x11b61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B61Cu;
            // 0x11b620: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b61c) {
            ctx->pc = 0x11B638u;
            goto label_11b638;
        }
    }
    ctx->pc = 0x11B624u;
label_11b624:
    // 0x11b624: 0xc045198  jal         func_114660
    ctx->pc = 0x11B624u;
    SET_GPR_U32(ctx, 31, 0x11B62Cu);
    ctx->pc = 0x11B628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B624u;
            // 0x11b628: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B62Cu; }
        if (ctx->pc != 0x11B62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B62Cu; }
        if (ctx->pc != 0x11B62Cu) { return; }
    }
    ctx->pc = 0x11B62Cu;
label_11b62c:
    // 0x11b62c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B62Cu;
    SET_GPR_U32(ctx, 31, 0x11B634u);
    ctx->pc = 0x11B630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B62Cu;
            // 0x11b630: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B634u; }
        if (ctx->pc != 0x11B634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B634u; }
        if (ctx->pc != 0x11B634u) { return; }
    }
    ctx->pc = 0x11B634u;
label_11b634:
    // 0x11b634: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11b634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11b638:
    // 0x11b638: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11b638u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b63c: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b63cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b640: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b640u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b644: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b644u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b648: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b648u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b64c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b64cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b650: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b650u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b654: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b654u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b658: 0x3e00008  jr          $ra
    ctx->pc = 0x11B658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B658u;
            // 0x11b65c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B294u: goto label_11b294;
            case 0x11B2B4u: goto label_11b2b4;
            case 0x11B2B8u: goto label_11b2b8;
            case 0x11B2D0u: goto label_11b2d0;
            case 0x11B2FCu: goto label_11b2fc;
            case 0x11B300u: goto label_11b300;
            case 0x11B304u: goto label_11b304;
            case 0x11B30Cu: goto label_11b30c;
            case 0x11B31Cu: goto label_11b31c;
            case 0x11B324u: goto label_11b324;
            case 0x11B32Cu: goto label_11b32c;
            case 0x11B348u: goto label_11b348;
            case 0x11B370u: goto label_11b370;
            case 0x11B380u: goto label_11b380;
            case 0x11B3A8u: goto label_11b3a8;
            case 0x11B3D0u: goto label_11b3d0;
            case 0x11B3F8u: goto label_11b3f8;
            case 0x11B408u: goto label_11b408;
            case 0x11B410u: goto label_11b410;
            case 0x11B418u: goto label_11b418;
            case 0x11B424u: goto label_11b424;
            case 0x11B434u: goto label_11b434;
            case 0x11B43Cu: goto label_11b43c;
            case 0x11B444u: goto label_11b444;
            case 0x11B44Cu: goto label_11b44c;
            case 0x11B450u: goto label_11b450;
            case 0x11B4BCu: goto label_11b4bc;
            case 0x11B4D4u: goto label_11b4d4;
            case 0x11B4D8u: goto label_11b4d8;
            case 0x11B4F8u: goto label_11b4f8;
            case 0x11B524u: goto label_11b524;
            case 0x11B530u: goto label_11b530;
            case 0x11B534u: goto label_11b534;
            case 0x11B53Cu: goto label_11b53c;
            case 0x11B558u: goto label_11b558;
            case 0x11B57Cu: goto label_11b57c;
            case 0x11B588u: goto label_11b588;
            case 0x11B5A4u: goto label_11b5a4;
            case 0x11B5E0u: goto label_11b5e0;
            case 0x11B5F0u: goto label_11b5f0;
            case 0x11B5F8u: goto label_11b5f8;
            case 0x11B600u: goto label_11b600;
            case 0x11B60Cu: goto label_11b60c;
            case 0x11B61Cu: goto label_11b61c;
            case 0x11B624u: goto label_11b624;
            case 0x11B62Cu: goto label_11b62c;
            case 0x11B634u: goto label_11b634;
            case 0x11B638u: goto label_11b638;
            case 0x11B6A4u: goto label_11b6a4;
            case 0x11B6BCu: goto label_11b6bc;
            case 0x11B6C0u: goto label_11b6c0;
            case 0x11B6E8u: goto label_11b6e8;
            case 0x11B714u: goto label_11b714;
            case 0x11B724u: goto label_11b724;
            case 0x11B728u: goto label_11b728;
            case 0x11B730u: goto label_11b730;
            case 0x11B74Cu: goto label_11b74c;
            case 0x11B768u: goto label_11b768;
            case 0x11B7A4u: goto label_11b7a4;
            case 0x11B7B4u: goto label_11b7b4;
            case 0x11B7BCu: goto label_11b7bc;
            case 0x11B7C4u: goto label_11b7c4;
            case 0x11B7D0u: goto label_11b7d0;
            case 0x11B7E0u: goto label_11b7e0;
            case 0x11B7E8u: goto label_11b7e8;
            case 0x11B7F0u: goto label_11b7f0;
            case 0x11B7F8u: goto label_11b7f8;
            case 0x11B7FCu: goto label_11b7fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B660u;
    // 0x11b660: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x11b660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x11b664: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b668: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b66c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11b66cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b670: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b674: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x11b674u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b678: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11b678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11b67c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11b67cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b680: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b684: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x11b684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11b688: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x11b688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x11b68c: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x11b68cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x11b690: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b694: 0x26f2ca40  addiu       $s2, $s7, -0x35C0
    ctx->pc = 0x11b694u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11b698: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b69c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B69Cu;
    SET_GPR_U32(ctx, 31, 0x11B6A4u);
    ctx->pc = 0x11B6A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B69Cu;
            // 0x11b6a0: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6A4u; }
        if (ctx->pc != 0x11B6A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6A4u; }
        if (ctx->pc != 0x11B6A4u) { return; }
    }
    ctx->pc = 0x11B6A4u;
label_11b6a4:
    // 0x11b6a4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11b6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11b6a8: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11b6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11b6ac: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B6ACu;
    {
        const bool branch_taken_0x11b6ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b6ac) {
            ctx->pc = 0x11B6B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6ACu;
            // 0x11b6b0: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B6C0u;
            goto label_11b6c0;
        }
    }
    ctx->pc = 0x11B6B4u;
    // 0x11b6b4: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11B6B4u;
    SET_GPR_U32(ctx, 31, 0x11B6BCu);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6BCu; }
        if (ctx->pc != 0x11B6BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6BCu; }
        if (ctx->pc != 0x11B6BCu) { return; }
    }
    ctx->pc = 0x11B6BCu;
label_11b6bc:
    // 0x11b6bc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11b6bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11b6c0:
    // 0x11b6c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b6c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b6c4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b6c8: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x11B6C8u;
    {
        const bool branch_taken_0x11b6c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6C8u;
            // 0x11b6cc: 0xa2420014  sb          $v0, 0x14($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b6c8) {
            ctx->pc = 0x11B714u;
            goto label_11b714;
        }
    }
    ctx->pc = 0x11B6D0u;
    // 0x11b6d0: 0x2e060400  sltiu       $a2, $s0, 0x400
    ctx->pc = 0x11b6d0u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b6d4: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b6d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b6d8: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b6d8u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b6dc: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b6dcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11b6e0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b6e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11b6e4: 0x0  nop
    ctx->pc = 0x11b6e4u;
    // NOP
label_11b6e8:
    // 0x11b6e8: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b6e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b6ec: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11B6ECu;
    {
        const bool branch_taken_0x11b6ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B6F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6ECu;
            // 0x11b6f0: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b6ec) {
            ctx->pc = 0x11B724u;
            goto label_11b724;
        }
    }
    ctx->pc = 0x11B6F4u;
    // 0x11b6f4: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11b6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11b6f8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b6f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b6fc: 0xa0830014  sb          $v1, 0x14($a0)
    ctx->pc = 0x11b6fcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 20), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b700: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b700u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b704: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B704u;
    {
        const bool branch_taken_0x11b704 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b704) {
            ctx->pc = 0x11B708u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B704u;
            // 0x11b708: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B6E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b6e8;
        }
    }
    ctx->pc = 0x11B70Cu;
    // 0x11b70c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B70Cu;
    {
        const bool branch_taken_0x11b70c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B70Cu;
            // 0x11b710: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b70c) {
            ctx->pc = 0x11B728u;
            goto label_11b728;
        }
    }
    ctx->pc = 0x11B714u;
label_11b714:
    // 0x11b714: 0x2e060400  sltiu       $a2, $s0, 0x400
    ctx->pc = 0x11b714u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b718: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b718u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b71c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b71cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b720: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b720u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11b724:
    // 0x11b724: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11b728:
    // 0x11b728: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B728u;
    {
        const bool branch_taken_0x11b728 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b728) {
            ctx->pc = 0x11B72Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B728u;
            // 0x11b72c: 0xa2400413  sb          $zero, 0x413($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1043), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B730u;
            goto label_11b730;
        }
    }
    ctx->pc = 0x11B730u;
label_11b730:
    // 0x11b730: 0x240203ff  addiu       $v0, $zero, 0x3FF
    ctx->pc = 0x11b730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x11b734: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11b734u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b738: 0x46800a  movz        $s0, $v0, $a2
    ctx->pc = 0x11b738u;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x11b73c: 0xae550010  sw          $s5, 0x10($s2)
    ctx->pc = 0x11b73cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 21));
    // 0x11b740: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11b740u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b744: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11B744u;
    SET_GPR_U32(ctx, 31, 0x11B74Cu);
    ctx->pc = 0x11B748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B744u;
            // 0x11b748: 0xae50000c  sw          $s0, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B74Cu; }
        if (ctx->pc != 0x11B74Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B74Cu; }
        if (ctx->pc != 0x11B74Cu) { return; }
    }
    ctx->pc = 0x11B74Cu;
label_11b74c:
    // 0x11b74c: 0x2690d680  addiu       $s0, $s4, -0x2980
    ctx->pc = 0x11b74cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x11b750: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11b750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b754: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b754u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b758: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11b758u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11b75c: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b760: 0xc045188  jal         func_114620
    ctx->pc = 0x11B760u;
    SET_GPR_U32(ctx, 31, 0x11B768u);
    ctx->pc = 0x11B764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B760u;
            // 0x11b764: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B768u; }
        if (ctx->pc != 0x11B768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B768u; }
        if (ctx->pc != 0x11B768u) { return; }
    }
    ctx->pc = 0x11B768u;
label_11b768:
    // 0x11b768: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11b768u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b76c: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11b76cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11b770: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11b770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b774: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11b774u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11b778: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11b778u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11b77c: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x11b77cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x11b780: 0x26e7ca40  addiu       $a3, $s7, -0x35C0
    ctx->pc = 0x11b780u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11b784: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x11b784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x11b788: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b788u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b78c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b78cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b790: 0x2408080c  addiu       $t0, $zero, 0x80C
    ctx->pc = 0x11b790u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11b794: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11b794u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b798: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b798u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b79c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B79Cu;
    SET_GPR_U32(ctx, 31, 0x11B7A4u);
    ctx->pc = 0x11B7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B79Cu;
            // 0x11b7a0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7A4u; }
        if (ctx->pc != 0x11B7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7A4u; }
        if (ctx->pc != 0x11B7A4u) { return; }
    }
    ctx->pc = 0x11B7A4u;
label_11b7a4:
    // 0x11b7a4: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B7A4u;
    {
        const bool branch_taken_0x11b7a4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B7A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7A4u;
            // 0x11b7a8: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7a4) {
            ctx->pc = 0x11B7C4u;
            goto label_11b7c4;
        }
    }
    ctx->pc = 0x11B7ACu;
    // 0x11b7ac: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7ACu;
    SET_GPR_U32(ctx, 31, 0x11B7B4u);
    ctx->pc = 0x11B7B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7ACu;
            // 0x11b7b0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7B4u; }
        if (ctx->pc != 0x11B7B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7B4u; }
        if (ctx->pc != 0x11B7B4u) { return; }
    }
    ctx->pc = 0x11B7B4u;
label_11b7b4:
    // 0x11b7b4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B7B4u;
    SET_GPR_U32(ctx, 31, 0x11B7BCu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7BCu; }
        if (ctx->pc != 0x11B7BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7BCu; }
        if (ctx->pc != 0x11B7BCu) { return; }
    }
    ctx->pc = 0x11B7BCu;
label_11b7bc:
    // 0x11b7bc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11B7BCu;
    {
        const bool branch_taken_0x11b7bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7BCu;
            // 0x11b7c0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7bc) {
            ctx->pc = 0x11B7FCu;
            goto label_11b7fc;
        }
    }
    ctx->pc = 0x11B7C4u;
label_11b7c4:
    // 0x11b7c4: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x11b7c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11b7c8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B7C8u;
    SET_GPR_U32(ctx, 31, 0x11B7D0u);
    ctx->pc = 0x11B7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7C8u;
            // 0x11b7cc: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7D0u; }
        if (ctx->pc != 0x11B7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7D0u; }
        if (ctx->pc != 0x11B7D0u) { return; }
    }
    ctx->pc = 0x11B7D0u;
label_11b7d0:
    // 0x11b7d0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B7D0u;
    {
        const bool branch_taken_0x11b7d0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b7d0) {
            ctx->pc = 0x11B7E8u;
            goto label_11b7e8;
        }
    }
    ctx->pc = 0x11B7D8u;
    // 0x11b7d8: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7D8u;
    SET_GPR_U32(ctx, 31, 0x11B7E0u);
    ctx->pc = 0x11B7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7D8u;
            // 0x11b7dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7E0u; }
        if (ctx->pc != 0x11B7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7E0u; }
        if (ctx->pc != 0x11B7E0u) { return; }
    }
    ctx->pc = 0x11B7E0u;
label_11b7e0:
    // 0x11b7e0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B7E0u;
    {
        const bool branch_taken_0x11b7e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7E0u;
            // 0x11b7e4: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7e0) {
            ctx->pc = 0x11B7FCu;
            goto label_11b7fc;
        }
    }
    ctx->pc = 0x11B7E8u;
label_11b7e8:
    // 0x11b7e8: 0xc045198  jal         func_114660
    ctx->pc = 0x11B7E8u;
    SET_GPR_U32(ctx, 31, 0x11B7F0u);
    ctx->pc = 0x11B7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7E8u;
            // 0x11b7ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F0u; }
        if (ctx->pc != 0x11B7F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F0u; }
        if (ctx->pc != 0x11B7F0u) { return; }
    }
    ctx->pc = 0x11B7F0u;
label_11b7f0:
    // 0x11b7f0: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7F0u;
    SET_GPR_U32(ctx, 31, 0x11B7F8u);
    ctx->pc = 0x11B7F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7F0u;
            // 0x11b7f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F8u; }
        if (ctx->pc != 0x11B7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F8u; }
        if (ctx->pc != 0x11B7F8u) { return; }
    }
    ctx->pc = 0x11B7F8u;
label_11b7f8:
    // 0x11b7f8: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11b7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11b7fc:
    // 0x11b7fc: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x11b7fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11b800: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11b800u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b804: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b804u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b808: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b808u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b80c: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b80cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b810: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b810u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b814: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b814u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b818: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b818u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b81c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b81cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b820: 0x3e00008  jr          $ra
    ctx->pc = 0x11B820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B820u;
            // 0x11b824: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B294u: goto label_11b294;
            case 0x11B2B4u: goto label_11b2b4;
            case 0x11B2B8u: goto label_11b2b8;
            case 0x11B2D0u: goto label_11b2d0;
            case 0x11B2FCu: goto label_11b2fc;
            case 0x11B300u: goto label_11b300;
            case 0x11B304u: goto label_11b304;
            case 0x11B30Cu: goto label_11b30c;
            case 0x11B31Cu: goto label_11b31c;
            case 0x11B324u: goto label_11b324;
            case 0x11B32Cu: goto label_11b32c;
            case 0x11B348u: goto label_11b348;
            case 0x11B370u: goto label_11b370;
            case 0x11B380u: goto label_11b380;
            case 0x11B3A8u: goto label_11b3a8;
            case 0x11B3D0u: goto label_11b3d0;
            case 0x11B3F8u: goto label_11b3f8;
            case 0x11B408u: goto label_11b408;
            case 0x11B410u: goto label_11b410;
            case 0x11B418u: goto label_11b418;
            case 0x11B424u: goto label_11b424;
            case 0x11B434u: goto label_11b434;
            case 0x11B43Cu: goto label_11b43c;
            case 0x11B444u: goto label_11b444;
            case 0x11B44Cu: goto label_11b44c;
            case 0x11B450u: goto label_11b450;
            case 0x11B4BCu: goto label_11b4bc;
            case 0x11B4D4u: goto label_11b4d4;
            case 0x11B4D8u: goto label_11b4d8;
            case 0x11B4F8u: goto label_11b4f8;
            case 0x11B524u: goto label_11b524;
            case 0x11B530u: goto label_11b530;
            case 0x11B534u: goto label_11b534;
            case 0x11B53Cu: goto label_11b53c;
            case 0x11B558u: goto label_11b558;
            case 0x11B57Cu: goto label_11b57c;
            case 0x11B588u: goto label_11b588;
            case 0x11B5A4u: goto label_11b5a4;
            case 0x11B5E0u: goto label_11b5e0;
            case 0x11B5F0u: goto label_11b5f0;
            case 0x11B5F8u: goto label_11b5f8;
            case 0x11B600u: goto label_11b600;
            case 0x11B60Cu: goto label_11b60c;
            case 0x11B61Cu: goto label_11b61c;
            case 0x11B624u: goto label_11b624;
            case 0x11B62Cu: goto label_11b62c;
            case 0x11B634u: goto label_11b634;
            case 0x11B638u: goto label_11b638;
            case 0x11B6A4u: goto label_11b6a4;
            case 0x11B6BCu: goto label_11b6bc;
            case 0x11B6C0u: goto label_11b6c0;
            case 0x11B6E8u: goto label_11b6e8;
            case 0x11B714u: goto label_11b714;
            case 0x11B724u: goto label_11b724;
            case 0x11B728u: goto label_11b728;
            case 0x11B730u: goto label_11b730;
            case 0x11B74Cu: goto label_11b74c;
            case 0x11B768u: goto label_11b768;
            case 0x11B7A4u: goto label_11b7a4;
            case 0x11B7B4u: goto label_11b7b4;
            case 0x11B7BCu: goto label_11b7bc;
            case 0x11B7C4u: goto label_11b7c4;
            case 0x11B7D0u: goto label_11b7d0;
            case 0x11B7E0u: goto label_11b7e0;
            case 0x11B7E8u: goto label_11b7e8;
            case 0x11B7F0u: goto label_11b7f0;
            case 0x11B7F8u: goto label_11b7f8;
            case 0x11B7FCu: goto label_11b7fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
