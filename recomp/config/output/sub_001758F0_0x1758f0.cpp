#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001758F0
// Address: 0x1758f0 - 0x175970
void sub_001758F0_0x1758f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001758F0_0x1758f0");
#endif

    switch (ctx->pc) {
        case 0x175914u: goto label_175914;
        case 0x175950u: goto label_175950;
        default: break;
    }

    ctx->pc = 0x1758f0u;

    // 0x1758f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1758f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1758f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1758f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1758f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1758f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1758fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1758fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175900: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x175900u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175904: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x175904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175908: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x175908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17590c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17590Cu;
    SET_GPR_U32(ctx, 31, 0x175914u);
    ctx->pc = 0x175910u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17590Cu;
            // 0x175910: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175914u; }
        if (ctx->pc != 0x175914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175914u; }
        if (ctx->pc != 0x175914u) { return; }
    }
    ctx->pc = 0x175914u;
label_175914:
    // 0x175914: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x175914u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x175918: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x175918u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17591c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x17591cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175920: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x175920u;
    {
        const bool branch_taken_0x175920 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175920u;
            // 0x175924: 0x34a50117  ori         $a1, $a1, 0x117 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)279);
        ctx->in_delay_slot = false;
        if (branch_taken_0x175920) {
            ctx->pc = 0x175948u;
            goto label_175948;
        }
    }
    ctx->pc = 0x175928u;
    // 0x175928: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175928u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17592c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17592cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175930: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175930u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175934: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x175934u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175938: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x175938u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17593c: 0x805a704  j           func_169C10
    ctx->pc = 0x17593Cu;
    ctx->pc = 0x175940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17593Cu;
            // 0x175940: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175944u;
    // 0x175944: 0x0  nop
    ctx->pc = 0x175944u;
    // NOP
label_175948:
    // 0x175948: 0xc05d65c  jal         func_175970
    ctx->pc = 0x175948u;
    SET_GPR_U32(ctx, 31, 0x175950u);
    ctx->pc = 0x17594Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175948u;
            // 0x17594c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175970u;
    if (runtime->hasFunction(0x175970u)) {
        auto targetFn = runtime->lookupFunction(0x175970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175950u; }
        if (ctx->pc != 0x175950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175970_0x175970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175950u; }
        if (ctx->pc != 0x175950u) { return; }
    }
    ctx->pc = 0x175950u;
label_175950:
    // 0x175950: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x175950u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175954: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175954u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175958: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175958u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17595c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17595cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175960: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x175960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175964: 0x3e00008  jr          $ra
    ctx->pc = 0x175964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175964u;
            // 0x175968: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175914u: goto label_175914;
            case 0x175948u: goto label_175948;
            case 0x175950u: goto label_175950;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17596Cu;
    // 0x17596c: 0x0  nop
    ctx->pc = 0x17596cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
