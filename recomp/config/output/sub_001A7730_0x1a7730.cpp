#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7730
// Address: 0x1a7730 - 0x1a77d0
void sub_001A7730_0x1a7730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7730_0x1a7730");
#endif

    switch (ctx->pc) {
        case 0x1a7770u: goto label_1a7770;
        default: break;
    }

    ctx->pc = 0x1a7730u;

    // 0x1a7730: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7734: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7738: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a773c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a773cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7740: 0x8c260a68  lw          $a2, 0xA68($at)
    ctx->pc = 0x1a7740u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7744: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7748: 0x61840  sll         $v1, $a2, 1
    ctx->pc = 0x1a7748u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1a774c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1a774cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1a7750: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7750u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7754: 0x433021  addu        $a2, $v0, $v1
    ctx->pc = 0x1a7754u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7758: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1a7758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1a775c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A775Cu;
    {
        const bool branch_taken_0x1a775c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A775Cu;
            // 0x1a7760: 0x308200ff  andi        $v0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a775c) {
            ctx->pc = 0x1A7778u;
            goto label_1a7778;
        }
    }
    ctx->pc = 0x1A7764u;
    // 0x1a7764: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7764u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7768: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7768u;
    SET_GPR_U32(ctx, 31, 0x1A7770u);
    ctx->pc = 0x1A776Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7768u;
            // 0x1a776c: 0x24842180  addiu       $a0, $a0, 0x2180 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7770u; }
        if (ctx->pc != 0x1A7770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7770u; }
        if (ctx->pc != 0x1A7770u) { return; }
    }
    ctx->pc = 0x1A7770u;
label_1a7770:
    // 0x1a7770: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1A7770u;
    {
        const bool branch_taken_0x1a7770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7770u;
            // 0x1a7774: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7770) {
            ctx->pc = 0x1A77C4u;
            goto label_1a77c4;
        }
    }
    ctx->pc = 0x1A7778u;
label_1a7778:
    // 0x1a7778: 0x30a3ffff  andi        $v1, $a1, 0xFFFF
    ctx->pc = 0x1a7778u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1a777c: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x1a777cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1a7780: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7780u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7784: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1a7784u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a7788: 0x3c024c00  lui         $v0, 0x4C00
    ctx->pc = 0x1a7788u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)19456 << 16));
    // 0x1a778c: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a778cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a7790: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7790u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7794: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a7794u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7798: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x1a7798u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1a779c: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a779cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a77a0: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a77a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a77a4: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A77A4u;
    {
        const bool branch_taken_0x1a77a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A77A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A77A4u;
            // 0x1a77a8: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a77a4) {
            ctx->pc = 0x1A77B8u;
            goto label_1a77b8;
        }
    }
    ctx->pc = 0x1A77ACu;
    // 0x1a77ac: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A77ACu;
    {
        const bool branch_taken_0x1a77ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a77ac) {
            ctx->pc = 0x1A77B8u;
            goto label_1a77b8;
        }
    }
    ctx->pc = 0x1A77B4u;
    // 0x1a77b4: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a77b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a77b8:
    // 0x1a77b8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a77b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a77bc: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a77bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a77c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a77c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a77c4:
    // 0x1a77c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a77c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a77c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A77C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A77CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A77C8u;
            // 0x1a77cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7770u: goto label_1a7770;
            case 0x1A7778u: goto label_1a7778;
            case 0x1A77B8u: goto label_1a77b8;
            case 0x1A77C4u: goto label_1a77c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A77D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
