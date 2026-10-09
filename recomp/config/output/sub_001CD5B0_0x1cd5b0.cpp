#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD5B0
// Address: 0x1cd5b0 - 0x1cd630
void sub_001CD5B0_0x1cd5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD5B0_0x1cd5b0");
#endif

    switch (ctx->pc) {
        case 0x1cd5fcu: goto label_1cd5fc;
        case 0x1cd614u: goto label_1cd614;
        default: break;
    }

    ctx->pc = 0x1cd5b0u;

    // 0x1cd5b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd5b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd5b4: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1cd5b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd5b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd5bc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1cd5bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1cd5c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd5c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd5c4: 0x62080  sll         $a0, $a2, 2
    ctx->pc = 0x1cd5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1cd5c8: 0x246366d0  addiu       $v1, $v1, 0x66D0
    ctx->pc = 0x1cd5c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26320));
    // 0x1cd5cc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1cd5ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd5d0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cd5d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cd5d4: 0x51202  srl         $v0, $a1, 8
    ctx->pc = 0x1cd5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x1cd5d8: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1cd5d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cd5dc: 0x30aa00ff  andi        $t2, $a1, 0xFF
    ctx->pc = 0x1cd5dcu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1cd5e0: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd5e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd5e4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd5e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd5e8: 0x304900ff  andi        $t1, $v0, 0xFF
    ctx->pc = 0x1cd5e8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1cd5ec: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd5ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd5f0: 0x24a55ff0  addiu       $a1, $a1, 0x5FF0
    ctx->pc = 0x1cd5f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24560));
    // 0x1cd5f4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD5F4u;
    SET_GPR_U32(ctx, 31, 0x1CD5FCu);
    ctx->pc = 0x1CD5F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD5F4u;
            // 0x1cd5f8: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD5FCu; }
        if (ctx->pc != 0x1CD5FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD5FCu; }
        if (ctx->pc != 0x1CD5FCu) { return; }
    }
    ctx->pc = 0x1CD5FCu;
label_1cd5fc:
    // 0x1cd5fc: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD5FCu;
    {
        const bool branch_taken_0x1cd5fc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD5FCu;
            // 0x1cd600: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd5fc) {
            ctx->pc = 0x1CD614u;
            goto label_1cd614;
        }
    }
    ctx->pc = 0x1CD604u;
    // 0x1cd604: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd604u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd608: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd60c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD60Cu;
    SET_GPR_U32(ctx, 31, 0x1CD614u);
    ctx->pc = 0x1CD610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD60Cu;
            // 0x1cd610: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD614u; }
        if (ctx->pc != 0x1CD614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD614u; }
        if (ctx->pc != 0x1CD614u) { return; }
    }
    ctx->pc = 0x1CD614u;
label_1cd614:
    // 0x1cd614: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd614u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd618: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd618u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd61c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd61cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd620: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd624: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD624u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD624u;
            // 0x1cd628: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD5FCu: goto label_1cd5fc;
            case 0x1CD614u: goto label_1cd614;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD62Cu;
    // 0x1cd62c: 0x0  nop
    ctx->pc = 0x1cd62cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
