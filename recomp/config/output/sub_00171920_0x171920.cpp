#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171920
// Address: 0x171920 - 0x1719a0
void sub_00171920_0x171920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171920_0x171920");
#endif

    switch (ctx->pc) {
        case 0x171944u: goto label_171944;
        case 0x171978u: goto label_171978;
        case 0x171988u: goto label_171988;
        default: break;
    }

    ctx->pc = 0x171920u;

    // 0x171920: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x171920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x171924: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171928: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17192c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17192cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x171930: 0x8cc21b30  lw          $v0, 0x1B30($a2)
    ctx->pc = 0x171930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x171934: 0x24500a48  addiu       $s0, $v0, 0xA48
    ctx->pc = 0x171934u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 2632));
    // 0x171938: 0x245109d8  addiu       $s1, $v0, 0x9D8
    ctx->pc = 0x171938u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 2520));
    // 0x17193c: 0xc05c398  jal         func_170E60
    ctx->pc = 0x17193Cu;
    SET_GPR_U32(ctx, 31, 0x171944u);
    ctx->pc = 0x171940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17193Cu;
            // 0x171940: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171944u; }
        if (ctx->pc != 0x171944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171944u; }
        if (ctx->pc != 0x171944u) { return; }
    }
    ctx->pc = 0x171944u;
label_171944:
    // 0x171944: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x171944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x171948: 0x50600010  beql        $v1, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x171948u;
    {
        const bool branch_taken_0x171948 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x171948) {
            ctx->pc = 0x17194Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171948u;
            // 0x17194c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17198Cu;
            goto label_17198c;
        }
    }
    ctx->pc = 0x171950u;
    // 0x171950: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x171950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171954: 0x5440000d  bnel        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x171954u;
    {
        const bool branch_taken_0x171954 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x171954) {
            ctx->pc = 0x171958u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171954u;
            // 0x171958: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17198Cu;
            goto label_17198c;
        }
    }
    ctx->pc = 0x17195Cu;
    // 0x17195c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17195cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171960: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x171960u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x171964: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x171964u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x171968: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x171968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17196c: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x17196cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x171970: 0xc05c620  jal         func_171880
    ctx->pc = 0x171970u;
    SET_GPR_U32(ctx, 31, 0x171978u);
    ctx->pc = 0x171974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171970u;
            // 0x171974: 0x24a50918  addiu       $a1, $a1, 0x918 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171880u;
    if (runtime->hasFunction(0x171880u)) {
        auto targetFn = runtime->lookupFunction(0x171880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171978u; }
        if (ctx->pc != 0x171978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171880_0x171880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171978u; }
        if (ctx->pc != 0x171978u) { return; }
    }
    ctx->pc = 0x171978u;
label_171978:
    // 0x171978: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x171978u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x17197c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17197cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171980: 0xc05c398  jal         func_170E60
    ctx->pc = 0x171980u;
    SET_GPR_U32(ctx, 31, 0x171988u);
    ctx->pc = 0x171984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171980u;
            // 0x171984: 0xae030014  sw          $v1, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171988u; }
        if (ctx->pc != 0x171988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171988u; }
        if (ctx->pc != 0x171988u) { return; }
    }
    ctx->pc = 0x171988u;
label_171988:
    // 0x171988: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171988u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17198c:
    // 0x17198c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17198cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171990: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171990u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171994: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x171994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171998: 0x3e00008  jr          $ra
    ctx->pc = 0x171998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17199Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171998u;
            // 0x17199c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171944u: goto label_171944;
            case 0x171978u: goto label_171978;
            case 0x171988u: goto label_171988;
            case 0x17198Cu: goto label_17198c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
