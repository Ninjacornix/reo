#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E2B0
// Address: 0x11e2b0 - 0x11e440
void sub_0011E2B0_0x11e2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E2B0_0x11e2b0");
#endif

    switch (ctx->pc) {
        case 0x11e2f8u: goto label_11e2f8;
        case 0x11e360u: goto label_11e360;
        case 0x11e3ccu: goto label_11e3cc;
        case 0x11e400u: goto label_11e400;
        default: break;
    }

    ctx->pc = 0x11e2b0u;

    // 0x11e2b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11e2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11e2b4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11e2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11e2b8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11e2b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11e2bc: 0x2442b3e8  addiu       $v0, $v0, -0x4C18
    ctx->pc = 0x11e2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11e2c0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11e2c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11e2c4: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x11e2c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e2c8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11e2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11e2cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e2ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e2d0: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x11e2d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11e2d4: 0x4610054  bgez        $v1, . + 4 + (0x54 << 2)
    ctx->pc = 0x11E2D4u;
    {
        const bool branch_taken_0x11e2d4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11E2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E2D4u;
            // 0x11e2d8: 0x8c460018  lw          $a2, 0x18($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e2d4) {
            ctx->pc = 0x11E428u;
            goto label_11e428;
        }
    }
    ctx->pc = 0x11E2DCu;
    // 0x11e2dc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11e2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11e2e0: 0x34421010  ori         $v0, $v0, 0x1010
    ctx->pc = 0x11e2e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4112);
    // 0x11e2e4: 0x8c520000  lw          $s2, 0x0($v0)
    ctx->pc = 0x11e2e4u;
    SET_GPR_S32(ctx, 18, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e2e8: 0x54c0000c  bnel        $a2, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x11E2E8u;
    {
        const bool branch_taken_0x11e2e8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x11e2e8) {
            ctx->pc = 0x11E2ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E2E8u;
            // 0x11e2ec: 0xdcc20020  ld          $v0, 0x20($a2) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E31Cu;
            goto label_11e31c;
        }
    }
    ctx->pc = 0x11E2F0u;
    // 0x11e2f0: 0xc0477d4  jal         func_11DF50
    ctx->pc = 0x11E2F0u;
    SET_GPR_U32(ctx, 31, 0x11E2F8u);
    ctx->pc = 0x11E2F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E2F0u;
            // 0x11e2f4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF50u;
    if (runtime->hasFunction(0x11DF50u)) {
        auto targetFn = runtime->lookupFunction(0x11DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E2F8u; }
        if (ctx->pc != 0x11E2F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF50_0x11df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E2F8u; }
        if (ctx->pc != 0x11E2F8u) { return; }
    }
    ctx->pc = 0x11E2F8u;
label_11e2f8:
    // 0x11e2f8: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e2fc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e300: 0x3484f7ff  ori         $a0, $a0, 0xF7FF
    ctx->pc = 0x11e300u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)63487);
    // 0x11e304: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e304u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e308: 0x2442024  and         $a0, $s2, $a0
    ctx->pc = 0x11e308u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & GPR_U64(ctx, 4));
    // 0x11e30c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e30cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e310: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e310u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e314: 0x80477d0  j           func_11DF40
    ctx->pc = 0x11E314u;
    ctx->pc = 0x11E318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E314u;
            // 0x11e318: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011DF40_0x11df40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11E31Cu;
label_11e31c:
    // 0x11e31c: 0xdcc30010  ld          $v1, 0x10($a2)
    ctx->pc = 0x11e31cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e320: 0xdcc40018  ld          $a0, 0x18($a2)
    ctx->pc = 0x11e320u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e324: 0x43102d  daddu       $v0, $v0, $v1
    ctx->pc = 0x11e324u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x11e328: 0x8cc60000  lw          $a2, 0x0($a2)
    ctx->pc = 0x11e328u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11e32c: 0x10c00019  beqz        $a2, . + 4 + (0x19 << 2)
    ctx->pc = 0x11E32Cu;
    {
        const bool branch_taken_0x11e32c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E32Cu;
            // 0x11e330: 0x44802f  dsubu       $s0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) - GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e32c) {
            ctx->pc = 0x11E394u;
            goto label_11e394;
        }
    }
    ctx->pc = 0x11E334u;
    // 0x11e334: 0xdcc20020  ld          $v0, 0x20($a2)
    ctx->pc = 0x11e334u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x11e338: 0x66037333  daddiu      $v1, $s0, 0x7333
    ctx->pc = 0x11e338u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)29491);
    // 0x11e33c: 0xdcc40010  ld          $a0, 0x10($a2)
    ctx->pc = 0x11e33cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e340: 0xdcc50018  ld          $a1, 0x18($a2)
    ctx->pc = 0x11e340u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e344: 0x44102d  daddu       $v0, $v0, $a0
    ctx->pc = 0x11e344u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x11e348: 0x45102f  dsubu       $v0, $v0, $a1
    ctx->pc = 0x11e348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 5));
    // 0x11e34c: 0x43182b  sltu        $v1, $v0, $v1
    ctx->pc = 0x11e34cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x11e350: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x11E350u;
    {
        const bool branch_taken_0x11e350 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E350u;
            // 0x11e354: 0x32510003  andi        $s1, $s2, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e350) {
            ctx->pc = 0x11E394u;
            goto label_11e394;
        }
    }
    ctx->pc = 0x11E358u;
    // 0x11e358: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11e358u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e35c: 0x0  nop
    ctx->pc = 0x11e35cu;
    // NOP
label_11e360:
    // 0x11e360: 0x8cc60000  lw          $a2, 0x0($a2)
    ctx->pc = 0x11e360u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11e364: 0x10c0000c  beqz        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x11E364u;
    {
        const bool branch_taken_0x11e364 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E364u;
            // 0x11e368: 0x66037333  daddiu      $v1, $s0, 0x7333 (Delay Slot)
        SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)29491);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e364) {
            ctx->pc = 0x11E398u;
            goto label_11e398;
        }
    }
    ctx->pc = 0x11E36Cu;
    // 0x11e36c: 0xdcc20020  ld          $v0, 0x20($a2)
    ctx->pc = 0x11e36cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x11e370: 0xdcc40010  ld          $a0, 0x10($a2)
    ctx->pc = 0x11e370u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e374: 0xdcc50018  ld          $a1, 0x18($a2)
    ctx->pc = 0x11e374u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e378: 0x44102d  daddu       $v0, $v0, $a0
    ctx->pc = 0x11e378u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x11e37c: 0x45102f  dsubu       $v0, $v0, $a1
    ctx->pc = 0x11e37cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 5));
    // 0x11e380: 0x43182b  sltu        $v1, $v0, $v1
    ctx->pc = 0x11e380u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x11e384: 0x50600005  beql        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x11E384u;
    {
        const bool branch_taken_0x11e384 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e384) {
            ctx->pc = 0x11E388u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E384u;
            // 0x11e388: 0x207102f  dsubu       $v0, $s0, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) - GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E39Cu;
            goto label_11e39c;
        }
    }
    ctx->pc = 0x11E38Cu;
    // 0x11e38c: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x11E38Cu;
    {
        const bool branch_taken_0x11e38c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E38Cu;
            // 0x11e390: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e38c) {
            ctx->pc = 0x11E360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11e360;
        }
    }
    ctx->pc = 0x11E394u;
label_11e394:
    // 0x11e394: 0x32510003  andi        $s1, $s2, 0x3
    ctx->pc = 0x11e394u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)3);
label_11e398:
    // 0x11e398: 0x207102f  dsubu       $v0, $s0, $a3
    ctx->pc = 0x11e398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) - GPR_U64(ctx, 7));
label_11e39c:
    // 0x11e39c: 0x28427333  slti        $v0, $v0, 0x7333
    ctx->pc = 0x11e39cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)29491) ? 1 : 0);
    // 0x11e3a0: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x11E3A0u;
    {
        const bool branch_taken_0x11e3a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E3A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E3A0u;
            // 0x11e3a4: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e3a0) {
            ctx->pc = 0x11E3F0u;
            goto label_11e3f0;
        }
    }
    ctx->pc = 0x11E3A8u;
    // 0x11e3a8: 0x112880  sll         $a1, $s1, 2
    ctx->pc = 0x11e3a8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x11e3ac: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x11e3acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x11e3b0: 0x24047333  addiu       $a0, $zero, 0x7333
    ctx->pc = 0x11e3b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 29491));
    // 0x11e3b4: 0xa42016  dsrlv       $a0, $a0, $a1
    ctx->pc = 0x11e3b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (GPR_U32(ctx, 5) & 0x3F));
    // 0x11e3b8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x11e3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e3bc: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11e3bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11e3c0: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x11e3c0u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x11e3c4: 0xc0477d4  jal         func_11DF50
    ctx->pc = 0x11E3C4u;
    SET_GPR_U32(ctx, 31, 0x11E3CCu);
    ctx->pc = 0x11E3C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E3C4u;
            // 0x11e3c8: 0x642021  addu        $a0, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF50u;
    if (runtime->hasFunction(0x11DF50u)) {
        auto targetFn = runtime->lookupFunction(0x11DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E3CCu; }
        if (ctx->pc != 0x11E3CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF50_0x11df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E3CCu; }
        if (ctx->pc != 0x11E3CCu) { return; }
    }
    ctx->pc = 0x11E3CCu;
label_11e3cc:
    // 0x11e3cc: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e3ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e3d0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e3d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e3d4: 0x3484f7ff  ori         $a0, $a0, 0xF7FF
    ctx->pc = 0x11e3d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)63487);
    // 0x11e3d8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e3d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e3dc: 0x2442024  and         $a0, $s2, $a0
    ctx->pc = 0x11e3dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & GPR_U64(ctx, 4));
    // 0x11e3e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e3e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e3e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e3e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e3e8: 0x80477d0  j           func_11DF40
    ctx->pc = 0x11E3E8u;
    ctx->pc = 0x11E3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E3E8u;
            // 0x11e3ec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011DF40_0x11df40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11E3F0u;
label_11e3f0:
    // 0x11e3f0: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11e3f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11e3f4: 0x3484f7ff  ori         $a0, $a0, 0xF7FF
    ctx->pc = 0x11e3f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)63487);
    // 0x11e3f8: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E3F8u;
    SET_GPR_U32(ctx, 31, 0x11E400u);
    ctx->pc = 0x11E3FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E3F8u;
            // 0x11e3fc: 0x2442024  and         $a0, $s2, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E400u; }
        if (ctx->pc != 0x11E400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E400u; }
        if (ctx->pc != 0x11E400u) { return; }
    }
    ctx->pc = 0x11E400u;
label_11e400:
    // 0x11e400: 0x112080  sll         $a0, $s1, 2
    ctx->pc = 0x11e400u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x11e404: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e408: 0x902016  dsrlv       $a0, $s0, $a0
    ctx->pc = 0x11e408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) >> (GPR_U32(ctx, 4) & 0x3F));
    // 0x11e40c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e40cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e410: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e410u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e414: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11e414u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11e418: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x11e418u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x11e41c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e41cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e420: 0x80477d4  j           func_11DF50
    ctx->pc = 0x11E420u;
    ctx->pc = 0x11E424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E420u;
            // 0x11e424: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF50u;
    if (runtime->hasFunction(0x11DF50u)) {
        auto targetFn = runtime->lookupFunction(0x11DF50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011DF50_0x11df50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11E428u;
label_11e428:
    // 0x11e428: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e42c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e42cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e430: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e430u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e434: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e434u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e438: 0x3e00008  jr          $ra
    ctx->pc = 0x11E438u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E43Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E438u;
            // 0x11e43c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E2F8u: goto label_11e2f8;
            case 0x11E31Cu: goto label_11e31c;
            case 0x11E360u: goto label_11e360;
            case 0x11E394u: goto label_11e394;
            case 0x11E398u: goto label_11e398;
            case 0x11E39Cu: goto label_11e39c;
            case 0x11E3CCu: goto label_11e3cc;
            case 0x11E3F0u: goto label_11e3f0;
            case 0x11E400u: goto label_11e400;
            case 0x11E428u: goto label_11e428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E440u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
