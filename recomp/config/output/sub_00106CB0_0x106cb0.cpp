#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106CB0
// Address: 0x106cb0 - 0x106d14
void sub_00106CB0_0x106cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106CB0_0x106cb0");
#endif

    switch (ctx->pc) {
        case 0x106cdcu: goto label_106cdc;
        case 0x106cecu: goto label_106cec;
        case 0x106cf8u: goto label_106cf8;
        default: break;
    }

    ctx->pc = 0x106cb0u;

    // 0x106cb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106cb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106cb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106cb8: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x106cb8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x106cbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106cc0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x106cc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106cc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106cc8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x106cc8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ccc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x106cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x106cd0: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x106cd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x106cd4: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x106CD4u;
    SET_GPR_U32(ctx, 31, 0x106CDCu);
    ctx->pc = 0x106CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CD4u;
            // 0x106cd8: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CDCu; }
        if (ctx->pc != 0x106CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CDCu; }
        if (ctx->pc != 0x106CDCu) { return; }
    }
    ctx->pc = 0x106CDCu;
label_106cdc:
    // 0x106cdc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106ce0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x106ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ce4: 0xc041b46  jal         func_106D18
    ctx->pc = 0x106CE4u;
    SET_GPR_U32(ctx, 31, 0x106CECu);
    ctx->pc = 0x106CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CE4u;
            // 0x106ce8: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106D18u;
    if (runtime->hasFunction(0x106D18u)) {
        auto targetFn = runtime->lookupFunction(0x106D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CECu; }
        if (ctx->pc != 0x106CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106D18_0x106d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CECu; }
        if (ctx->pc != 0x106CECu) { return; }
    }
    ctx->pc = 0x106CECu;
label_106cec:
    // 0x106cec: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106cecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106cf0: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x106CF0u;
    SET_GPR_U32(ctx, 31, 0x106CF8u);
    ctx->pc = 0x106CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CF0u;
            // 0x106cf4: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CF8u; }
        if (ctx->pc != 0x106CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CF8u; }
        if (ctx->pc != 0x106CF8u) { return; }
    }
    ctx->pc = 0x106CF8u;
label_106cf8:
    // 0x106cf8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x106cf8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106cfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106d00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106d00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106d04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106d04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106d08: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x106d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106d0c: 0x3e00008  jr          $ra
    ctx->pc = 0x106D0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106D0Cu;
            // 0x106d10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106CDCu: goto label_106cdc;
            case 0x106CECu: goto label_106cec;
            case 0x106CF8u: goto label_106cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106D14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
