#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B078
// Address: 0x15b078 - 0x15b148
void sub_0015B078_0x15b078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B078_0x15b078");
#endif

    switch (ctx->pc) {
        case 0x15b0a8u: goto label_15b0a8;
        case 0x15b0c8u: goto label_15b0c8;
        case 0x15b0f0u: goto label_15b0f0;
        case 0x15b0f8u: goto label_15b0f8;
        case 0x15b104u: goto label_15b104;
        case 0x15b110u: goto label_15b110;
        case 0x15b118u: goto label_15b118;
        case 0x15b120u: goto label_15b120;
        case 0x15b128u: goto label_15b128;
        case 0x15b130u: goto label_15b130;
        default: break;
    }

    ctx->pc = 0x15b078u;

    // 0x15b078: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x15b078u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x15b07c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15b07cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15b080: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15b080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15b084: 0x24634c68  addiu       $v1, $v1, 0x4C68
    ctx->pc = 0x15b084u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19560));
    // 0x15b088: 0x2442e5c0  addiu       $v0, $v0, -0x1A40
    ctx->pc = 0x15b088u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960576));
    // 0x15b08c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b08cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b090: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15b090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15b094: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15b094u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b098: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15b098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15b09c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15b09cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b0a0: 0xc056c52  jal         func_15B148
    ctx->pc = 0x15B0A0u;
    SET_GPR_U32(ctx, 31, 0x15B0A8u);
    ctx->pc = 0x15B0A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B0A0u;
            // 0x15b0a4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B148u;
    if (runtime->hasFunction(0x15B148u)) {
        auto targetFn = runtime->lookupFunction(0x15B148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0A8u; }
        if (ctx->pc != 0x15B0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B148_0x15b148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0A8u; }
        if (ctx->pc != 0x15B0A8u) { return; }
    }
    ctx->pc = 0x15B0A8u;
label_15b0a8:
    // 0x15b0a8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15b0a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b0ac: 0x1080000e  beqz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x15B0ACu;
    {
        const bool branch_taken_0x15b0ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15b0ac) {
            ctx->pc = 0x15B0E8u;
            goto label_15b0e8;
        }
    }
    ctx->pc = 0x15B0B4u;
    // 0x15b0b4: 0x3c03ff03  lui         $v1, 0xFF03
    ctx->pc = 0x15b0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65283 << 16));
    // 0x15b0b8: 0x3463ff05  ori         $v1, $v1, 0xFF05
    ctx->pc = 0x15b0b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65285);
    // 0x15b0bc: 0x5083001e  beql        $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x15B0BCu;
    {
        const bool branch_taken_0x15b0bc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x15b0bc) {
            ctx->pc = 0x15B0C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15B0BCu;
            // 0x15b0c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15B138u;
            goto label_15b138;
        }
    }
    ctx->pc = 0x15B0C4u;
    // 0x15b0c4: 0x0  nop
    ctx->pc = 0x15b0c4u;
    // NOP
label_15b0c8:
    // 0x15b0c8: 0x0  nop
    ctx->pc = 0x15b0c8u;
    // NOP
    // 0x15b0cc: 0x0  nop
    ctx->pc = 0x15b0ccu;
    // NOP
    // 0x15b0d0: 0x0  nop
    ctx->pc = 0x15b0d0u;
    // NOP
    // 0x15b0d4: 0x0  nop
    ctx->pc = 0x15b0d4u;
    // NOP
    // 0x15b0d8: 0x0  nop
    ctx->pc = 0x15b0d8u;
    // NOP
    // 0x15b0dc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x15B0DCu;
    {
        const bool branch_taken_0x15b0dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x15b0dc) {
            ctx->pc = 0x15B0C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15b0c8;
        }
    }
    ctx->pc = 0x15B0E4u;
    // 0x15b0e4: 0x0  nop
    ctx->pc = 0x15b0e4u;
    // NOP
label_15b0e8:
    // 0x15b0e8: 0xc056c70  jal         func_15B1C0
    ctx->pc = 0x15B0E8u;
    SET_GPR_U32(ctx, 31, 0x15B0F0u);
    ctx->pc = 0x15B1C0u;
    if (runtime->hasFunction(0x15B1C0u)) {
        auto targetFn = runtime->lookupFunction(0x15B1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0F0u; }
        if (ctx->pc != 0x15B0F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B1C0_0x15b1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0F0u; }
        if (ctx->pc != 0x15B0F0u) { return; }
    }
    ctx->pc = 0x15B0F0u;
label_15b0f0:
    // 0x15b0f0: 0xc056c7a  jal         func_15B1E8
    ctx->pc = 0x15B0F0u;
    SET_GPR_U32(ctx, 31, 0x15B0F8u);
    ctx->pc = 0x15B0F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B0F0u;
            // 0x15b0f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B1E8u;
    if (runtime->hasFunction(0x15B1E8u)) {
        auto targetFn = runtime->lookupFunction(0x15B1E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0F8u; }
        if (ctx->pc != 0x15B0F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B1E8_0x15b1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B0F8u; }
        if (ctx->pc != 0x15B0F8u) { return; }
    }
    ctx->pc = 0x15B0F8u;
label_15b0f8:
    // 0x15b0f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15b0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b0fc: 0xc056cd8  jal         func_15B360
    ctx->pc = 0x15B0FCu;
    SET_GPR_U32(ctx, 31, 0x15B104u);
    ctx->pc = 0x15B100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B0FCu;
            // 0x15b100: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B360u;
    if (runtime->hasFunction(0x15B360u)) {
        auto targetFn = runtime->lookupFunction(0x15B360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B104u; }
        if (ctx->pc != 0x15B104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B360_0x15b360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B104u; }
        if (ctx->pc != 0x15B104u) { return; }
    }
    ctx->pc = 0x15B104u;
label_15b104:
    // 0x15b104: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b104u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b108: 0xc056384  jal         func_158E10
    ctx->pc = 0x15B108u;
    SET_GPR_U32(ctx, 31, 0x15B110u);
    ctx->pc = 0x15B10Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B108u;
            // 0x15b10c: 0x8c504cc0  lw          $s0, 0x4CC0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19648)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158E10u;
    if (runtime->hasFunction(0x158E10u)) {
        auto targetFn = runtime->lookupFunction(0x158E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B110u; }
        if (ctx->pc != 0x15B110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158E10_0x158e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B110u; }
        if (ctx->pc != 0x15B110u) { return; }
    }
    ctx->pc = 0x15B110u;
label_15b110:
    // 0x15b110: 0xc056c82  jal         func_15B208
    ctx->pc = 0x15B110u;
    SET_GPR_U32(ctx, 31, 0x15B118u);
    ctx->pc = 0x15B114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B110u;
            // 0x15b114: 0x260406e0  addiu       $a0, $s0, 0x6E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1760));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B208u;
    if (runtime->hasFunction(0x15B208u)) {
        auto targetFn = runtime->lookupFunction(0x15B208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B118u; }
        if (ctx->pc != 0x15B118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B208_0x15b208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B118u; }
        if (ctx->pc != 0x15B118u) { return; }
    }
    ctx->pc = 0x15B118u;
label_15b118:
    // 0x15b118: 0xc056cb8  jal         func_15B2E0
    ctx->pc = 0x15B118u;
    SET_GPR_U32(ctx, 31, 0x15B120u);
    ctx->pc = 0x15B2E0u;
    if (runtime->hasFunction(0x15B2E0u)) {
        auto targetFn = runtime->lookupFunction(0x15B2E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B120u; }
        if (ctx->pc != 0x15B120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B2E0_0x15b2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B120u; }
        if (ctx->pc != 0x15B120u) { return; }
    }
    ctx->pc = 0x15B120u;
label_15b120:
    // 0x15b120: 0xc056cd6  jal         func_15B358
    ctx->pc = 0x15B120u;
    SET_GPR_U32(ctx, 31, 0x15B128u);
    ctx->pc = 0x15B124u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B120u;
            // 0x15b124: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B358u;
    if (runtime->hasFunction(0x15B358u)) {
        auto targetFn = runtime->lookupFunction(0x15B358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B128u; }
        if (ctx->pc != 0x15B128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B358_0x15b358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B128u; }
        if (ctx->pc != 0x15B128u) { return; }
    }
    ctx->pc = 0x15B128u;
label_15b128:
    // 0x15b128: 0xc056df6  jal         func_15B7D8
    ctx->pc = 0x15B128u;
    SET_GPR_U32(ctx, 31, 0x15B130u);
    ctx->pc = 0x15B7D8u;
    if (runtime->hasFunction(0x15B7D8u)) {
        auto targetFn = runtime->lookupFunction(0x15B7D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B130u; }
        if (ctx->pc != 0x15B130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7D8_0x15b7d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B130u; }
        if (ctx->pc != 0x15B130u) { return; }
    }
    ctx->pc = 0x15B130u;
label_15b130:
    // 0x15b130: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15b130u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b134: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b134u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15b138:
    // 0x15b138: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15b138u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b13c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15b13cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b140: 0x3e00008  jr          $ra
    ctx->pc = 0x15B140u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B140u;
            // 0x15b144: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B0A8u: goto label_15b0a8;
            case 0x15B0C8u: goto label_15b0c8;
            case 0x15B0E8u: goto label_15b0e8;
            case 0x15B0F0u: goto label_15b0f0;
            case 0x15B0F8u: goto label_15b0f8;
            case 0x15B104u: goto label_15b104;
            case 0x15B110u: goto label_15b110;
            case 0x15B118u: goto label_15b118;
            case 0x15B120u: goto label_15b120;
            case 0x15B128u: goto label_15b128;
            case 0x15B130u: goto label_15b130;
            case 0x15B138u: goto label_15b138;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B148u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
