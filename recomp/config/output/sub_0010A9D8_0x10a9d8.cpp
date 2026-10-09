#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A9D8
// Address: 0x10a9d8 - 0x10aa58
void sub_0010A9D8_0x10a9d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A9D8_0x10a9d8");
#endif

    switch (ctx->pc) {
        case 0x10aa18u: goto label_10aa18;
        case 0x10aa38u: goto label_10aa38;
        default: break;
    }

    ctx->pc = 0x10a9d8u;

    // 0x10a9d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a9d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a9dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a9e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a9e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a9e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a9e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10a9e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10a9ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x10a9f0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x10a9f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a9f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x10a9f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x10a9f8: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10a9f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a9fc: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x10a9fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x10aa00: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10AA00u;
    {
        const bool branch_taken_0x10aa00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AA04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA00u;
            // 0x10aa04: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa00) {
            ctx->pc = 0x10AA18u;
            goto label_10aa18;
        }
    }
    ctx->pc = 0x10AA08u;
    // 0x10aa08: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa0c: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x10aa0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10aa10: 0xc041abe  jal         func_106AF8
    ctx->pc = 0x10AA10u;
    SET_GPR_U32(ctx, 31, 0x10AA18u);
    ctx->pc = 0x10AA14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA10u;
            // 0x10aa14: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AF8u;
    if (runtime->hasFunction(0x106AF8u)) {
        auto targetFn = runtime->lookupFunction(0x106AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA18u; }
        if (ctx->pc != 0x10AA18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106AF8_0x106af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA18u; }
        if (ctx->pc != 0x10AA18u) { return; }
    }
    ctx->pc = 0x10AA18u;
label_10aa18:
    // 0x10aa18: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10aa18u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10aa1c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10aa1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa20: 0x8605000e  lh          $a1, 0xE($s0)
    ctx->pc = 0x10aa20u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x10aa24: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x10aa24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa28: 0x3042efff  andi        $v0, $v0, 0xEFFF
    ctx->pc = 0x10aa28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)61439);
    // 0x10aa2c: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa30: 0xc043e4c  jal         func_10F930
    ctx->pc = 0x10AA30u;
    SET_GPR_U32(ctx, 31, 0x10AA38u);
    ctx->pc = 0x10AA34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA30u;
            // 0x10aa34: 0xa602000c  sh          $v0, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F930u;
    if (runtime->hasFunction(0x10F930u)) {
        auto targetFn = runtime->lookupFunction(0x10F930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA38u; }
        if (ctx->pc != 0x10AA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F930_0x10f930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA38u; }
        if (ctx->pc != 0x10AA38u) { return; }
    }
    ctx->pc = 0x10AA38u;
label_10aa38:
    // 0x10aa38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10aa38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aa3c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10aa3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10aa40: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10aa40u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10aa44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10aa44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10aa48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x10aa48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10aa4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x10aa4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10aa50: 0x3e00008  jr          $ra
    ctx->pc = 0x10AA50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10AA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA50u;
            // 0x10aa54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10AA18u: goto label_10aa18;
            case 0x10AA38u: goto label_10aa38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10AA58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
