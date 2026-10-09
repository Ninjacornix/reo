#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001759A0
// Address: 0x1759a0 - 0x175a38
void sub_001759A0_0x1759a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001759A0_0x1759a0");
#endif

    switch (ctx->pc) {
        case 0x1759c4u: goto label_1759c4;
        default: break;
    }

    ctx->pc = 0x1759a0u;

    // 0x1759a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1759a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1759a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1759a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1759a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1759a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1759ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1759acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1759b0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1759b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1759b4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1759b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1759b8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1759b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1759bc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1759BCu;
    SET_GPR_U32(ctx, 31, 0x1759C4u);
    ctx->pc = 0x1759C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1759BCu;
            // 0x1759c0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1759C4u; }
        if (ctx->pc != 0x1759C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1759C4u; }
        if (ctx->pc != 0x1759C4u) { return; }
    }
    ctx->pc = 0x1759C4u;
label_1759c4:
    // 0x1759c4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1759c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1759c8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1759c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1759cc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1759CCu;
    {
        const bool branch_taken_0x1759cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1759D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1759CCu;
            // 0x1759d0: 0x34a5011c  ori         $a1, $a1, 0x11C (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)284);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1759cc) {
            ctx->pc = 0x1759F0u;
            goto label_1759f0;
        }
    }
    ctx->pc = 0x1759D4u;
    // 0x1759d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1759d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1759d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1759d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1759dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1759dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1759e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1759e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1759e4: 0x805a704  j           func_169C10
    ctx->pc = 0x1759E4u;
    ctx->pc = 0x1759E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1759E4u;
            // 0x1759e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1759ECu;
    // 0x1759ec: 0x0  nop
    ctx->pc = 0x1759ecu;
    // NOP
label_1759f0:
    // 0x1759f0: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1759f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1759f4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1759F4u;
    {
        const bool branch_taken_0x1759f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1759F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1759F4u;
            // 0x1759f8: 0x2602010c  addiu       $v0, $s0, 0x10C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 268));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1759f4) {
            ctx->pc = 0x175A10u;
            goto label_175a10;
        }
    }
    ctx->pc = 0x1759FCu;
    // 0x1759fc: 0x8e030108  lw          $v1, 0x108($s0)
    ctx->pc = 0x1759fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 264)));
    // 0x175a00: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x175a00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x175a04: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x175A04u;
    {
        const bool branch_taken_0x175a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x175A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175A04u;
            // 0x175a08: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175a04) {
            ctx->pc = 0x175A18u;
            goto label_175a18;
        }
    }
    ctx->pc = 0x175A0Cu;
    // 0x175a0c: 0x0  nop
    ctx->pc = 0x175a0cu;
    // NOP
label_175a10:
    // 0x175a10: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x175a10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x175a14: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x175a14u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
label_175a18:
    // 0x175a18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175a18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175a1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x175a1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175a20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175a20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175a24: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x175a24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175a28: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x175a28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175a2c: 0x3e00008  jr          $ra
    ctx->pc = 0x175A2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175A2Cu;
            // 0x175a30: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1759C4u: goto label_1759c4;
            case 0x1759F0u: goto label_1759f0;
            case 0x175A10u: goto label_175a10;
            case 0x175A18u: goto label_175a18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175A34u;
    // 0x175a34: 0x0  nop
    ctx->pc = 0x175a34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
