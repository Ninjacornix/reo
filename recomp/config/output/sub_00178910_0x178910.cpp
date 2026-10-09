#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178910
// Address: 0x178910 - 0x178a78
void sub_00178910_0x178910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178910_0x178910");
#endif

    switch (ctx->pc) {
        case 0x178948u: goto label_178948;
        case 0x1789e4u: goto label_1789e4;
        case 0x1789f8u: goto label_1789f8;
        case 0x178a48u: goto label_178a48;
        case 0x178a50u: goto label_178a50;
        case 0x178a5cu: goto label_178a5c;
        default: break;
    }

    ctx->pc = 0x178910u;

    // 0x178910: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x178910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x178914: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178918: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17891c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17891cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178920: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x178920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x178924: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x178924u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178928: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x178928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17892c: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x17892cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178930: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x178930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x178934: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x178934u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178938: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x178938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17893c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17893cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x178940: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x178940u;
    SET_GPR_U32(ctx, 31, 0x178948u);
    ctx->pc = 0x178944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178940u;
            // 0x178944: 0x26301cc0  addiu       $s0, $s1, 0x1CC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 7360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178948u; }
        if (ctx->pc != 0x178948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178948u; }
        if (ctx->pc != 0x178948u) { return; }
    }
    ctx->pc = 0x178948u;
label_178948:
    // 0x178948: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x178948u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17894c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17894cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178950: 0x34a50191  ori         $a1, $a1, 0x191
    ctx->pc = 0x178950u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)401);
    // 0x178954: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x178954u;
    {
        const bool branch_taken_0x178954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178954u;
            // 0x178958: 0x24030008  addiu       $v1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178954) {
            ctx->pc = 0x178980u;
            goto label_178980;
        }
    }
    ctx->pc = 0x17895Cu;
    // 0x17895c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17895cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178960: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178960u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178964: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178964u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178968: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x178968u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17896c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17896cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178970: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178970u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178974: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x178974u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178978: 0x805a704  j           func_169C10
    ctx->pc = 0x178978u;
    ctx->pc = 0x17897Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178978u;
            // 0x17897c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178980u;
label_178980:
    // 0x178980: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x178980u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x178984: 0x1643000e  bne         $s2, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x178984u;
    {
        const bool branch_taken_0x178984 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 3));
        ctx->pc = 0x178988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178984u;
            // 0x178988: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178984) {
            ctx->pc = 0x1789C0u;
            goto label_1789c0;
        }
    }
    ctx->pc = 0x17898Cu;
    // 0x17898c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17898cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178990: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178990u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178994: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x178994u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x178998: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178998u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17899c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17899cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1789a0: 0x34a50602  ori         $a1, $a1, 0x602
    ctx->pc = 0x1789a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1538);
    // 0x1789a4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1789a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1789a8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1789a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1789ac: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1789acu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1789b0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1789b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1789b4: 0x805a704  j           func_169C10
    ctx->pc = 0x1789B4u;
    ctx->pc = 0x1789B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1789B4u;
            // 0x1789b8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1789BCu;
    // 0x1789bc: 0x0  nop
    ctx->pc = 0x1789bcu;
    // NOP
label_1789c0:
    // 0x1789c0: 0x158100  sll         $s0, $s5, 4
    ctx->pc = 0x1789c0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 21), 4));
    // 0x1789c4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1789c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789c8: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x1789c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1789cc: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1789ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789d0: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1789d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1789d4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1789d4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1789d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789dc: 0xc05e318  jal         func_178C60
    ctx->pc = 0x1789DCu;
    SET_GPR_U32(ctx, 31, 0x1789E4u);
    ctx->pc = 0x1789E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1789DCu;
            // 0x1789e0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178C60u;
    if (runtime->hasFunction(0x178C60u)) {
        auto targetFn = runtime->lookupFunction(0x178C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1789E4u; }
        if (ctx->pc != 0x1789E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178C60_0x178c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1789E4u; }
        if (ctx->pc != 0x1789E4u) { return; }
    }
    ctx->pc = 0x1789E4u;
label_1789e4:
    // 0x1789e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1789e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789e8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1789e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789ec: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x1789ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789f0: 0xc059bc6  jal         func_166F18
    ctx->pc = 0x1789F0u;
    SET_GPR_U32(ctx, 31, 0x1789F8u);
    ctx->pc = 0x1789F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1789F0u;
            // 0x1789f4: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166F18u;
    if (runtime->hasFunction(0x166F18u)) {
        auto targetFn = runtime->lookupFunction(0x166F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1789F8u; }
        if (ctx->pc != 0x1789F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F18_0x166f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1789F8u; }
        if (ctx->pc != 0x1789F8u) { return; }
    }
    ctx->pc = 0x1789F8u;
label_1789f8:
    // 0x1789f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1789f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1789fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1789fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178a00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178a00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178a04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178a04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178a08: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x178a08u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178a0c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x178a0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178a10: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178a10u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178a14: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x178a14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178a18: 0x3e00008  jr          $ra
    ctx->pc = 0x178A18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178A18u;
            // 0x178a1c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178948u: goto label_178948;
            case 0x178980u: goto label_178980;
            case 0x1789C0u: goto label_1789c0;
            case 0x1789E4u: goto label_1789e4;
            case 0x1789F8u: goto label_1789f8;
            case 0x178A48u: goto label_178a48;
            case 0x178A50u: goto label_178a50;
            case 0x178A5Cu: goto label_178a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178A20u;
    // 0x178a20: 0x3e00008  jr          $ra
    ctx->pc = 0x178A20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178A20u;
            // 0x178a24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178948u: goto label_178948;
            case 0x178980u: goto label_178980;
            case 0x1789C0u: goto label_1789c0;
            case 0x1789E4u: goto label_1789e4;
            case 0x1789F8u: goto label_1789f8;
            case 0x178A48u: goto label_178a48;
            case 0x178A50u: goto label_178a50;
            case 0x178A5Cu: goto label_178a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178A28u;
    // 0x178a28: 0x3e00008  jr          $ra
    ctx->pc = 0x178A28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178A28u;
            // 0x178a2c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178948u: goto label_178948;
            case 0x178980u: goto label_178980;
            case 0x1789C0u: goto label_1789c0;
            case 0x1789E4u: goto label_1789e4;
            case 0x1789F8u: goto label_1789f8;
            case 0x178A48u: goto label_178a48;
            case 0x178A50u: goto label_178a50;
            case 0x178A5Cu: goto label_178a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178A30u;
    // 0x178a30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178a30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178a34: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178a38: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178a3c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178a40: 0xc05e29e  jal         func_178A78
    ctx->pc = 0x178A40u;
    SET_GPR_U32(ctx, 31, 0x178A48u);
    ctx->pc = 0x178A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A40u;
            // 0x178a44: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178A78u;
    if (runtime->hasFunction(0x178A78u)) {
        auto targetFn = runtime->lookupFunction(0x178A78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A48u; }
        if (ctx->pc != 0x178A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178A78_0x178a78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A48u; }
        if (ctx->pc != 0x178A48u) { return; }
    }
    ctx->pc = 0x178A48u;
label_178a48:
    // 0x178a48: 0xc05e2e2  jal         func_178B88
    ctx->pc = 0x178A48u;
    SET_GPR_U32(ctx, 31, 0x178A50u);
    ctx->pc = 0x178A4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A48u;
            // 0x178a4c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178B88u;
    if (runtime->hasFunction(0x178B88u)) {
        auto targetFn = runtime->lookupFunction(0x178B88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A50u; }
        if (ctx->pc != 0x178A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178B88_0x178b88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A50u; }
        if (ctx->pc != 0x178A50u) { return; }
    }
    ctx->pc = 0x178A50u;
label_178a50:
    // 0x178a50: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x178a50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178a54: 0xc05e2c0  jal         func_178B00
    ctx->pc = 0x178A54u;
    SET_GPR_U32(ctx, 31, 0x178A5Cu);
    ctx->pc = 0x178A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A54u;
            // 0x178a58: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178B00u;
    if (runtime->hasFunction(0x178B00u)) {
        auto targetFn = runtime->lookupFunction(0x178B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A5Cu; }
        if (ctx->pc != 0x178A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178B00_0x178b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A5Cu; }
        if (ctx->pc != 0x178A5Cu) { return; }
    }
    ctx->pc = 0x178A5Cu;
label_178a5c:
    // 0x178a5c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178a5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178a60: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x178a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178a64: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178a64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178a68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178a68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178a6c: 0x3e00008  jr          $ra
    ctx->pc = 0x178A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178A6Cu;
            // 0x178a70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178948u: goto label_178948;
            case 0x178980u: goto label_178980;
            case 0x1789C0u: goto label_1789c0;
            case 0x1789E4u: goto label_1789e4;
            case 0x1789F8u: goto label_1789f8;
            case 0x178A48u: goto label_178a48;
            case 0x178A50u: goto label_178a50;
            case 0x178A5Cu: goto label_178a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178A74u;
    // 0x178a74: 0x0  nop
    ctx->pc = 0x178a74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
