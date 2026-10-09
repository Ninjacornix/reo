#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B1B8
// Address: 0x12b1b8 - 0x12b260
void sub_0012B1B8_0x12b1b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B1B8_0x12b1b8");
#endif

    switch (ctx->pc) {
        case 0x12b204u: goto label_12b204;
        case 0x12b220u: goto label_12b220;
        case 0x12b238u: goto label_12b238;
        case 0x12b24cu: goto label_12b24c;
        default: break;
    }

    ctx->pc = 0x12b1b8u;

    // 0x12b1b8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b1bc: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b1bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b1c0: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b1c0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b1c4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b1c8: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b1c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b1cc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b1ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b1d0: 0x24a5aba0  addiu       $a1, $a1, -0x5460
    ctx->pc = 0x12b1d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945696));
    // 0x12b1d4: 0x24630570  addiu       $v1, $v1, 0x570
    ctx->pc = 0x12b1d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1392));
    // 0x12b1d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b1d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b1dc: 0x24060800  addiu       $a2, $zero, 0x800
    ctx->pc = 0x12b1dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x12b1e0: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b1e4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b1e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b1e8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b1ec: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b1f0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b1f4: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b1f8: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b1f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b1fc: 0xc045108  jal         func_114420
    ctx->pc = 0x12B1FCu;
    SET_GPR_U32(ctx, 31, 0x12B204u);
    ctx->pc = 0x12B200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B1FCu;
            // 0x12b200: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B204u; }
        if (ctx->pc != 0x12B204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B204u; }
        if (ctx->pc != 0x12B204u) { return; }
    }
    ctx->pc = 0x12B204u;
label_12b204:
    // 0x12b204: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b204u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b208: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b208u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b20c: 0x247004d8  addiu       $s0, $v1, 0x4D8
    ctx->pc = 0x12b20cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 1240));
    // 0x12b210: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b210u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b214: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b218: 0xc045110  jal         func_114440
    ctx->pc = 0x12B218u;
    SET_GPR_U32(ctx, 31, 0x12B220u);
    ctx->pc = 0x12B21Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B218u;
            // 0x12b21c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B220u; }
        if (ctx->pc != 0x12B220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B220u; }
        if (ctx->pc != 0x12B220u) { return; }
    }
    ctx->pc = 0x12B220u;
label_12b220:
    // 0x12b220: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12b220u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b224: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x12B224u;
    {
        const bool branch_taken_0x12b224 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B224u;
            // 0x12b228: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b224) {
            ctx->pc = 0x12B240u;
            goto label_12b240;
        }
    }
    ctx->pc = 0x12B22Cu;
    // 0x12b22c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b22cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b230: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12B230u;
    SET_GPR_U32(ctx, 31, 0x12B238u);
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B238u; }
        if (ctx->pc != 0x12B238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B238u; }
        if (ctx->pc != 0x12B238u) { return; }
    }
    ctx->pc = 0x12B238u;
label_12b238:
    // 0x12b238: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12b238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b23c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b23cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
label_12b240:
    // 0x12b240: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b240u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b244: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B244u;
    SET_GPR_U32(ctx, 31, 0x12B24Cu);
    ctx->pc = 0x12B248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B244u;
            // 0x12b248: 0x8c450464  lw          $a1, 0x464($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1124)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B24Cu; }
        if (ctx->pc != 0x12B24Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B24Cu; }
        if (ctx->pc != 0x12B24Cu) { return; }
    }
    ctx->pc = 0x12B24Cu;
label_12b24c:
    // 0x12b24c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b24cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b250: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b254: 0x3e00008  jr          $ra
    ctx->pc = 0x12B254u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B254u;
            // 0x12b258: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B204u: goto label_12b204;
            case 0x12B220u: goto label_12b220;
            case 0x12B238u: goto label_12b238;
            case 0x12B240u: goto label_12b240;
            case 0x12B24Cu: goto label_12b24c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B25Cu;
    // 0x12b25c: 0x0  nop
    ctx->pc = 0x12b25cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
