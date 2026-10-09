#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E88C0
// Address: 0x1e88c0 - 0x1e8f30
void sub_001E88C0_0x1e88c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E88C0_0x1e88c0");
#endif

    switch (ctx->pc) {
        case 0x1e88d8u: goto label_1e88d8;
        case 0x1e8990u: goto label_1e8990;
        case 0x1e89a8u: goto label_1e89a8;
        case 0x1e89c0u: goto label_1e89c0;
        case 0x1e89f4u: goto label_1e89f4;
        case 0x1e8a28u: goto label_1e8a28;
        case 0x1e8a68u: goto label_1e8a68;
        case 0x1e8ae8u: goto label_1e8ae8;
        case 0x1e8b00u: goto label_1e8b00;
        case 0x1e8b18u: goto label_1e8b18;
        case 0x1e8b3cu: goto label_1e8b3c;
        case 0x1e8b54u: goto label_1e8b54;
        case 0x1e8b9cu: goto label_1e8b9c;
        case 0x1e8bc8u: goto label_1e8bc8;
        case 0x1e8bf0u: goto label_1e8bf0;
        case 0x1e8c08u: goto label_1e8c08;
        case 0x1e8c2cu: goto label_1e8c2c;
        case 0x1e8c5cu: goto label_1e8c5c;
        case 0x1e8c88u: goto label_1e8c88;
        case 0x1e8c94u: goto label_1e8c94;
        case 0x1e8d00u: goto label_1e8d00;
        case 0x1e8d60u: goto label_1e8d60;
        case 0x1e8e4cu: goto label_1e8e4c;
        case 0x1e8e5cu: goto label_1e8e5c;
        case 0x1e8e74u: goto label_1e8e74;
        case 0x1e8ea8u: goto label_1e8ea8;
        case 0x1e8ee0u: goto label_1e8ee0;
        default: break;
    }

    ctx->pc = 0x1e88c0u;

    // 0x1e88c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e88c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e88c4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e88c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e88c8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e88c8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e88cc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e88ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e88d0: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1e88d0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e88d4: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e88d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1e88d8:
    // 0x1e88d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e88d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e88dc: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e88dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e88e0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E88E0u;
    {
        const bool branch_taken_0x1e88e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e88e0) {
            ctx->pc = 0x1E88F0u;
            goto label_1e88f0;
        }
    }
    ctx->pc = 0x1E88E8u;
    // 0x1e88e8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E88E8u;
    {
        const bool branch_taken_0x1e88e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e88e8) {
            ctx->pc = 0x1E8954u;
            goto label_1e8954;
        }
    }
    ctx->pc = 0x1E88F0u;
label_1e88f0:
    // 0x1e88f0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e88f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e88f4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e88f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e88f8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e88f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e88fc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e88fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8900: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8900u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8904: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8908: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e890c: 0x84430000  lh          $v1, 0x0($v0)
    ctx->pc = 0x1e890cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e8910: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1e8910u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8914: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E8914u;
    {
        const bool branch_taken_0x1e8914 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e8914) {
            ctx->pc = 0x1E8940u;
            goto label_1e8940;
        }
    }
    ctx->pc = 0x1E891Cu;
    // 0x1e891c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e891cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8920: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8920u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8924: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8924u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8928: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e892c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e892cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8930: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8934: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8938: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E8938u;
    {
        const bool branch_taken_0x1e8938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8938) {
            ctx->pc = 0x1E8958u;
            goto label_1e8958;
        }
    }
    ctx->pc = 0x1E8940u;
label_1e8940:
    // 0x1e8940: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8940u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8944: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e8944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e8948: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e8948u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e894c: 0x1000ffe2  b           . + 4 + (-0x1E << 2)
    ctx->pc = 0x1E894Cu;
    {
        const bool branch_taken_0x1e894c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e894c) {
            ctx->pc = 0x1E88D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e88d8;
        }
    }
    ctx->pc = 0x1E8954u;
label_1e8954:
    // 0x1e8954: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e8954u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e8958:
    // 0x1e8958: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8958u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e895c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e895cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e8960: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e8960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e8964: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E88D8u: goto label_1e88d8;
            case 0x1E88F0u: goto label_1e88f0;
            case 0x1E8940u: goto label_1e8940;
            case 0x1E8954u: goto label_1e8954;
            case 0x1E8958u: goto label_1e8958;
            case 0x1E8990u: goto label_1e8990;
            case 0x1E89A8u: goto label_1e89a8;
            case 0x1E89C0u: goto label_1e89c0;
            case 0x1E89D8u: goto label_1e89d8;
            case 0x1E89F4u: goto label_1e89f4;
            case 0x1E8A0Cu: goto label_1e8a0c;
            case 0x1E8A28u: goto label_1e8a28;
            case 0x1E8A40u: goto label_1e8a40;
            case 0x1E8A68u: goto label_1e8a68;
            case 0x1E8A84u: goto label_1e8a84;
            case 0x1E8A94u: goto label_1e8a94;
            case 0x1E8AE8u: goto label_1e8ae8;
            case 0x1E8B00u: goto label_1e8b00;
            case 0x1E8B18u: goto label_1e8b18;
            case 0x1E8B30u: goto label_1e8b30;
            case 0x1E8B3Cu: goto label_1e8b3c;
            case 0x1E8B54u: goto label_1e8b54;
            case 0x1E8B6Cu: goto label_1e8b6c;
            case 0x1E8B9Cu: goto label_1e8b9c;
            case 0x1E8BB4u: goto label_1e8bb4;
            case 0x1E8BC8u: goto label_1e8bc8;
            case 0x1E8BF0u: goto label_1e8bf0;
            case 0x1E8C08u: goto label_1e8c08;
            case 0x1E8C2Cu: goto label_1e8c2c;
            case 0x1E8C44u: goto label_1e8c44;
            case 0x1E8C5Cu: goto label_1e8c5c;
            case 0x1E8C74u: goto label_1e8c74;
            case 0x1E8C88u: goto label_1e8c88;
            case 0x1E8C90u: goto label_1e8c90;
            case 0x1E8C94u: goto label_1e8c94;
            case 0x1E8CACu: goto label_1e8cac;
            case 0x1E8D00u: goto label_1e8d00;
            case 0x1E8D34u: goto label_1e8d34;
            case 0x1E8D48u: goto label_1e8d48;
            case 0x1E8D60u: goto label_1e8d60;
            case 0x1E8D78u: goto label_1e8d78;
            case 0x1E8E14u: goto label_1e8e14;
            case 0x1E8E4Cu: goto label_1e8e4c;
            case 0x1E8E5Cu: goto label_1e8e5c;
            case 0x1E8E74u: goto label_1e8e74;
            case 0x1E8E8Cu: goto label_1e8e8c;
            case 0x1E8EA8u: goto label_1e8ea8;
            case 0x1E8EC0u: goto label_1e8ec0;
            case 0x1E8EE0u: goto label_1e8ee0;
            case 0x1E8EFCu: goto label_1e8efc;
            case 0x1E8F18u: goto label_1e8f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E896Cu;
    // 0x1e896c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e896cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e8970: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e8970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e8974: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e8974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e8978: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8978u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e897c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e897cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8980: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8980u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8984: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e8984u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e8988: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8988u;
    SET_GPR_U32(ctx, 31, 0x1E8990u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8990u; }
        if (ctx->pc != 0x1E8990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8990u; }
        if (ctx->pc != 0x1E8990u) { return; }
    }
    ctx->pc = 0x1E8990u;
label_1e8990:
    // 0x1e8990: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8990u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8994: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8998: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e8998u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e899c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e899cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e89a0: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E89A0u;
    SET_GPR_U32(ctx, 31, 0x1E89A8u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89A8u; }
        if (ctx->pc != 0x1E89A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89A8u; }
        if (ctx->pc != 0x1E89A8u) { return; }
    }
    ctx->pc = 0x1E89A8u;
label_1e89a8:
    // 0x1e89a8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e89a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e89ac: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e89acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e89b0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E89B0u;
    {
        const bool branch_taken_0x1e89b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e89b0) {
            ctx->pc = 0x1E89D8u;
            goto label_1e89d8;
        }
    }
    ctx->pc = 0x1E89B8u;
    // 0x1e89b8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E89B8u;
    SET_GPR_U32(ctx, 31, 0x1E89C0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89C0u; }
        if (ctx->pc != 0x1E89C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89C0u; }
        if (ctx->pc != 0x1E89C0u) { return; }
    }
    ctx->pc = 0x1E89C0u;
label_1e89c0:
    // 0x1e89c0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e89c0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e89c4: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e89c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e89c8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e89c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e89cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e89ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e89d0: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E89D0u;
    {
        const bool branch_taken_0x1e89d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e89d0) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E89D8u;
label_1e89d8:
    // 0x1e89d8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e89d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e89dc: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e89dcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e89e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e89e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e89e4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E89E4u;
    {
        const bool branch_taken_0x1e89e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e89e4) {
            ctx->pc = 0x1E8A0Cu;
            goto label_1e8a0c;
        }
    }
    ctx->pc = 0x1E89ECu;
    // 0x1e89ec: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E89ECu;
    SET_GPR_U32(ctx, 31, 0x1E89F4u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89F4u; }
        if (ctx->pc != 0x1E89F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E89F4u; }
        if (ctx->pc != 0x1E89F4u) { return; }
    }
    ctx->pc = 0x1E89F4u;
label_1e89f4:
    // 0x1e89f4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e89f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e89f8: 0x2402006d  addiu       $v0, $zero, 0x6D
    ctx->pc = 0x1e89f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x1e89fc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e89fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8a00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8a04: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E8A04u;
    {
        const bool branch_taken_0x1e8a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a04) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A0Cu;
label_1e8a0c:
    // 0x1e8a0c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e8a0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8a10: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8a10u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8a14: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8a18: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8A18u;
    {
        const bool branch_taken_0x1e8a18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8a18) {
            ctx->pc = 0x1E8A40u;
            goto label_1e8a40;
        }
    }
    ctx->pc = 0x1E8A20u;
    // 0x1e8a20: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8A20u;
    SET_GPR_U32(ctx, 31, 0x1E8A28u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A28u; }
        if (ctx->pc != 0x1E8A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A28u; }
        if (ctx->pc != 0x1E8A28u) { return; }
    }
    ctx->pc = 0x1E8A28u;
label_1e8a28:
    // 0x1e8a28: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8a28u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a2c: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8a30: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8a30u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8a34: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8a38: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E8A38u;
    {
        const bool branch_taken_0x1e8a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a38) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A40u;
label_1e8a40:
    // 0x1e8a40: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e8a40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8a44: 0x88430007  lwl         $v1, 0x7($v0)
    ctx->pc = 0x1e8a44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x1e8a48: 0x98430004  lwr         $v1, 0x4($v0)
    ctx->pc = 0x1e8a48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x1e8a4c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e8a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8a50: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e8a50u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e8a54: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1e8a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a58: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e8a58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a5c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1e8a5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a60: 0xc075ec0  jal         func_1D7B00
    ctx->pc = 0x1E8A60u;
    SET_GPR_U32(ctx, 31, 0x1E8A68u);
    ctx->pc = 0x1D7B00u;
    if (runtime->hasFunction(0x1D7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A68u; }
        if (ctx->pc != 0x1E8A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B00_0x1d7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8A68u; }
        if (ctx->pc != 0x1E8A68u) { return; }
    }
    ctx->pc = 0x1E8A68u;
label_1e8a68:
    // 0x1e8a68: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a68u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8a6c: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a70: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E8A70u;
    {
        const bool branch_taken_0x1e8a70 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8a70) {
            ctx->pc = 0x1E8A84u;
            goto label_1e8a84;
        }
    }
    ctx->pc = 0x1E8A78u;
    // 0x1e8a78: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8a78u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a7c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1E8A7Cu;
    {
        const bool branch_taken_0x1e8a7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8a7c) {
            ctx->pc = 0x1E8A94u;
            goto label_1e8a94;
        }
    }
    ctx->pc = 0x1E8A84u;
label_1e8a84:
    // 0x1e8a84: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e8a84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8a88: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e8a88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8a8c: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8a8cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8a90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e8a90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e8a94:
    // 0x1e8a94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8a94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8a98: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e8a98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e8a9c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e8a9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e8aa0: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e8aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e8aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E88D8u: goto label_1e88d8;
            case 0x1E88F0u: goto label_1e88f0;
            case 0x1E8940u: goto label_1e8940;
            case 0x1E8954u: goto label_1e8954;
            case 0x1E8958u: goto label_1e8958;
            case 0x1E8990u: goto label_1e8990;
            case 0x1E89A8u: goto label_1e89a8;
            case 0x1E89C0u: goto label_1e89c0;
            case 0x1E89D8u: goto label_1e89d8;
            case 0x1E89F4u: goto label_1e89f4;
            case 0x1E8A0Cu: goto label_1e8a0c;
            case 0x1E8A28u: goto label_1e8a28;
            case 0x1E8A40u: goto label_1e8a40;
            case 0x1E8A68u: goto label_1e8a68;
            case 0x1E8A84u: goto label_1e8a84;
            case 0x1E8A94u: goto label_1e8a94;
            case 0x1E8AE8u: goto label_1e8ae8;
            case 0x1E8B00u: goto label_1e8b00;
            case 0x1E8B18u: goto label_1e8b18;
            case 0x1E8B30u: goto label_1e8b30;
            case 0x1E8B3Cu: goto label_1e8b3c;
            case 0x1E8B54u: goto label_1e8b54;
            case 0x1E8B6Cu: goto label_1e8b6c;
            case 0x1E8B9Cu: goto label_1e8b9c;
            case 0x1E8BB4u: goto label_1e8bb4;
            case 0x1E8BC8u: goto label_1e8bc8;
            case 0x1E8BF0u: goto label_1e8bf0;
            case 0x1E8C08u: goto label_1e8c08;
            case 0x1E8C2Cu: goto label_1e8c2c;
            case 0x1E8C44u: goto label_1e8c44;
            case 0x1E8C5Cu: goto label_1e8c5c;
            case 0x1E8C74u: goto label_1e8c74;
            case 0x1E8C88u: goto label_1e8c88;
            case 0x1E8C90u: goto label_1e8c90;
            case 0x1E8C94u: goto label_1e8c94;
            case 0x1E8CACu: goto label_1e8cac;
            case 0x1E8D00u: goto label_1e8d00;
            case 0x1E8D34u: goto label_1e8d34;
            case 0x1E8D48u: goto label_1e8d48;
            case 0x1E8D60u: goto label_1e8d60;
            case 0x1E8D78u: goto label_1e8d78;
            case 0x1E8E14u: goto label_1e8e14;
            case 0x1E8E4Cu: goto label_1e8e4c;
            case 0x1E8E5Cu: goto label_1e8e5c;
            case 0x1E8E74u: goto label_1e8e74;
            case 0x1E8E8Cu: goto label_1e8e8c;
            case 0x1E8EA8u: goto label_1e8ea8;
            case 0x1E8EC0u: goto label_1e8ec0;
            case 0x1E8EE0u: goto label_1e8ee0;
            case 0x1E8EFCu: goto label_1e8efc;
            case 0x1E8F18u: goto label_1e8f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8AACu;
    // 0x1e8aac: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e8aacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e8ab0: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e8ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e8ab4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e8ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e8ab8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8ab8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8abc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8abcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8ac0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8ac4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e8ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e8ac8: 0x27c30030  addiu       $v1, $fp, 0x30
    ctx->pc = 0x1e8ac8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 48));
    // 0x1e8acc: 0x27828048  addiu       $v0, $gp, -0x7FB8
    ctx->pc = 0x1e8accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934600));
    // 0x1e8ad0: 0x68440007  ldl         $a0, 0x7($v0)
    ctx->pc = 0x1e8ad0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1e8ad4: 0x6c440000  ldr         $a0, 0x0($v0)
    ctx->pc = 0x1e8ad4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1e8ad8: 0xb0640007  sdl         $a0, 0x7($v1)
    ctx->pc = 0x1e8ad8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1e8adc: 0xb4640000  sdr         $a0, 0x0($v1)
    ctx->pc = 0x1e8adcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1e8ae0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8AE0u;
    SET_GPR_U32(ctx, 31, 0x1E8AE8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8AE8u; }
        if (ctx->pc != 0x1E8AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8AE8u; }
        if (ctx->pc != 0x1E8AE8u) { return; }
    }
    ctx->pc = 0x1E8AE8u;
label_1e8ae8:
    // 0x1e8ae8: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8ae8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8aec: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8aecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8af0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e8af0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e8af4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e8af4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8af8: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E8AF8u;
    SET_GPR_U32(ctx, 31, 0x1E8B00u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B00u; }
        if (ctx->pc != 0x1E8B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B00u; }
        if (ctx->pc != 0x1E8B00u) { return; }
    }
    ctx->pc = 0x1E8B00u;
label_1e8b00:
    // 0x1e8b00: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8b00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e8b04: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8b08: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8B08u;
    {
        const bool branch_taken_0x1e8b08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8b08) {
            ctx->pc = 0x1E8B30u;
            goto label_1e8b30;
        }
    }
    ctx->pc = 0x1E8B10u;
    // 0x1e8b10: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8B10u;
    SET_GPR_U32(ctx, 31, 0x1E8B18u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B18u; }
        if (ctx->pc != 0x1E8B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B18u; }
        if (ctx->pc != 0x1E8B18u) { return; }
    }
    ctx->pc = 0x1E8B18u;
label_1e8b18:
    // 0x1e8b18: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8b18u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8b1c: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8b20: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8b20u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8b24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8b28: 0x100000ba  b           . + 4 + (0xBA << 2)
    ctx->pc = 0x1E8B28u;
    {
        const bool branch_taken_0x1e8b28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8b28) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8B30u;
label_1e8b30:
    // 0x1e8b30: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e8b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8b34: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E8B34u;
    SET_GPR_U32(ctx, 31, 0x1E8B3Cu);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B3Cu; }
        if (ctx->pc != 0x1E8B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B3Cu; }
        if (ctx->pc != 0x1E8B3Cu) { return; }
    }
    ctx->pc = 0x1E8B3Cu;
label_1e8b3c:
    // 0x1e8b3c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e8b3cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8b40: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8b40u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8b44: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8B44u;
    {
        const bool branch_taken_0x1e8b44 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8b44) {
            ctx->pc = 0x1E8B6Cu;
            goto label_1e8b6c;
        }
    }
    ctx->pc = 0x1E8B4Cu;
    // 0x1e8b4c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8B4Cu;
    SET_GPR_U32(ctx, 31, 0x1E8B54u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B54u; }
        if (ctx->pc != 0x1E8B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B54u; }
        if (ctx->pc != 0x1E8B54u) { return; }
    }
    ctx->pc = 0x1E8B54u;
label_1e8b54:
    // 0x1e8b54: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8b54u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8b58: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8b5c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8b60: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8b60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8b64: 0x100000ab  b           . + 4 + (0xAB << 2)
    ctx->pc = 0x1E8B64u;
    {
        const bool branch_taken_0x1e8b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8b64) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8B6Cu;
label_1e8b6c:
    // 0x1e8b6c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8b70: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8b70u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8b74: 0x24020ff5  addiu       $v0, $zero, 0xFF5
    ctx->pc = 0x1e8b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4085));
    // 0x1e8b78: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1E8B78u;
    {
        const bool branch_taken_0x1e8b78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8b78) {
            ctx->pc = 0x1E8BB4u;
            goto label_1e8bb4;
        }
    }
    ctx->pc = 0x1E8B80u;
    // 0x1e8b80: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8b80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8b84: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8b84u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8b88: 0x24020ff6  addiu       $v0, $zero, 0xFF6
    ctx->pc = 0x1e8b88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4086));
    // 0x1e8b8c: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8B8Cu;
    {
        const bool branch_taken_0x1e8b8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8b8c) {
            ctx->pc = 0x1E8BB4u;
            goto label_1e8bb4;
        }
    }
    ctx->pc = 0x1E8B94u;
    // 0x1e8b94: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8B94u;
    SET_GPR_U32(ctx, 31, 0x1E8B9Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B9Cu; }
        if (ctx->pc != 0x1E8B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8B9Cu; }
        if (ctx->pc != 0x1E8B9Cu) { return; }
    }
    ctx->pc = 0x1E8B9Cu;
label_1e8b9c:
    // 0x1e8b9c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8b9cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ba0: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8ba4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8ba8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8bac: 0x10000099  b           . + 4 + (0x99 << 2)
    ctx->pc = 0x1E8BACu;
    {
        const bool branch_taken_0x1e8bac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8bac) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8BB4u;
label_1e8bb4:
    // 0x1e8bb4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8bb8: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e8bb8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e8bbc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8bbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8bc0: 0xc075f00  jal         func_1D7C00
    ctx->pc = 0x1E8BC0u;
    SET_GPR_U32(ctx, 31, 0x1E8BC8u);
    ctx->pc = 0x1D7C00u;
    if (runtime->hasFunction(0x1D7C00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8BC8u; }
        if (ctx->pc != 0x1E8BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7C00_0x1d7c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8BC8u; }
        if (ctx->pc != 0x1E8BC8u) { return; }
    }
    ctx->pc = 0x1E8BC8u;
label_1e8bc8:
    // 0x1e8bc8: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e8bc8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8bcc: 0x87c3000c  lh          $v1, 0xC($fp)
    ctx->pc = 0x1e8bccu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8bd0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8bd4: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1E8BD4u;
    {
        const bool branch_taken_0x1e8bd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8bd4) {
            ctx->pc = 0x1E8C08u;
            goto label_1e8c08;
        }
    }
    ctx->pc = 0x1E8BDCu;
    // 0x1e8bdc: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8bdcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8be0: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8BE0u;
    {
        const bool branch_taken_0x1e8be0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8be0) {
            ctx->pc = 0x1E8C08u;
            goto label_1e8c08;
        }
    }
    ctx->pc = 0x1E8BE8u;
    // 0x1e8be8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8BE8u;
    SET_GPR_U32(ctx, 31, 0x1E8BF0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8BF0u; }
        if (ctx->pc != 0x1E8BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8BF0u; }
        if (ctx->pc != 0x1E8BF0u) { return; }
    }
    ctx->pc = 0x1E8BF0u;
label_1e8bf0:
    // 0x1e8bf0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8bf0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8bf4: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8bf8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8bfc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8c00: 0x10000084  b           . + 4 + (0x84 << 2)
    ctx->pc = 0x1E8C00u;
    {
        const bool branch_taken_0x1e8c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c00) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8C08u;
label_1e8c08:
    // 0x1e8c08: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e8c08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e8c0c: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e8c0cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e8c10: 0x27c3000e  addiu       $v1, $fp, 0xE
    ctx->pc = 0x1e8c10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 14));
    // 0x1e8c14: 0x27c60010  addiu       $a2, $fp, 0x10
    ctx->pc = 0x1e8c14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e8c18: 0x27c70014  addiu       $a3, $fp, 0x14
    ctx->pc = 0x1e8c18u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1e8c1c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8c1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8c20: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e8c20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8c24: 0xc076078  jal         func_1D81E0
    ctx->pc = 0x1E8C24u;
    SET_GPR_U32(ctx, 31, 0x1E8C2Cu);
    ctx->pc = 0x1D81E0u;
    if (runtime->hasFunction(0x1D81E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D81E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C2Cu; }
        if (ctx->pc != 0x1E8C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D81E0_0x1d81e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C2Cu; }
        if (ctx->pc != 0x1E8C2Cu) { return; }
    }
    ctx->pc = 0x1E8C2Cu;
label_1e8c2c:
    // 0x1e8c2c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e8c2cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8c30: 0x87c2000c  lh          $v0, 0xC($fp)
    ctx->pc = 0x1e8c30u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8c34: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E8C34u;
    {
        const bool branch_taken_0x1e8c34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c34) {
            ctx->pc = 0x1E8C44u;
            goto label_1e8c44;
        }
    }
    ctx->pc = 0x1E8C3Cu;
    // 0x1e8c3c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1E8C3Cu;
    {
        const bool branch_taken_0x1e8c3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c3c) {
            ctx->pc = 0x1E8C90u;
            goto label_1e8c90;
        }
    }
    ctx->pc = 0x1E8C44u;
label_1e8c44:
    // 0x1e8c44: 0x87c3000c  lh          $v1, 0xC($fp)
    ctx->pc = 0x1e8c44u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8c48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8c4c: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8C4Cu;
    {
        const bool branch_taken_0x1e8c4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8c4c) {
            ctx->pc = 0x1E8C74u;
            goto label_1e8c74;
        }
    }
    ctx->pc = 0x1E8C54u;
    // 0x1e8c54: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8C54u;
    SET_GPR_U32(ctx, 31, 0x1E8C5Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C5Cu; }
        if (ctx->pc != 0x1E8C5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C5Cu; }
        if (ctx->pc != 0x1E8C5Cu) { return; }
    }
    ctx->pc = 0x1E8C5Cu;
label_1e8c5c:
    // 0x1e8c5c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8c5cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8c60: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8c64: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8c64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8c68: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8c68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8c6c: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x1E8C6Cu;
    {
        const bool branch_taken_0x1e8c6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c6c) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8C74u;
label_1e8c74:
    // 0x1e8c74: 0x27c20030  addiu       $v0, $fp, 0x30
    ctx->pc = 0x1e8c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 48));
    // 0x1e8c78: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8c78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8c7c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e8c7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8c80: 0xc079fb4  jal         func_1E7ED0
    ctx->pc = 0x1E8C80u;
    SET_GPR_U32(ctx, 31, 0x1E8C88u);
    ctx->pc = 0x1E7ED0u;
    if (runtime->hasFunction(0x1E7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1E7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C88u; }
        if (ctx->pc != 0x1E8C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7ED0_0x1e7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8C88u; }
        if (ctx->pc != 0x1E8C88u) { return; }
    }
    ctx->pc = 0x1E8C88u;
label_1e8c88:
    // 0x1e8c88: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x1E8C88u;
    {
        const bool branch_taken_0x1e8c88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c88) {
            ctx->pc = 0x1E8C08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e8c08;
        }
    }
    ctx->pc = 0x1E8C90u;
label_1e8c90:
    // 0x1e8c90: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e8c90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_1e8c94:
    // 0x1e8c94: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e8c94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8c98: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e8c98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e8c9c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E8C9Cu;
    {
        const bool branch_taken_0x1e8c9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8c9c) {
            ctx->pc = 0x1E8CACu;
            goto label_1e8cac;
        }
    }
    ctx->pc = 0x1E8CA4u;
    // 0x1e8ca4: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1E8CA4u;
    {
        const bool branch_taken_0x1e8ca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8ca4) {
            ctx->pc = 0x1E8D48u;
            goto label_1e8d48;
        }
    }
    ctx->pc = 0x1E8CACu;
label_1e8cac:
    // 0x1e8cac: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e8cacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8cb0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8cb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8cb4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8cb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8cbc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8cc0: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8cc4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8cc8: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e8cc8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e8ccc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e8cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e8cd0: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E8CD0u;
    {
        const bool branch_taken_0x1e8cd0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e8cd0) {
            ctx->pc = 0x1E8D00u;
            goto label_1e8d00;
        }
    }
    ctx->pc = 0x1E8CD8u;
    // 0x1e8cd8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e8cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8cdc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8cdcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ce0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8ce4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8ce8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8cec: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8cf0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8cf4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8cf4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8cf8: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E8CF8u;
    SET_GPR_U32(ctx, 31, 0x1E8D00u);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8D00u; }
        if (ctx->pc != 0x1E8D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8D00u; }
        if (ctx->pc != 0x1E8D00u) { return; }
    }
    ctx->pc = 0x1E8D00u;
label_1e8d00:
    // 0x1e8d00: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e8d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8d04: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8d04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8d08: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8d08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8d0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8d10: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8d10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8d14: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8d14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8d18: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e8d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e8d1c: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e8d1cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e8d20: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8d20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8d24: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E8D24u;
    {
        const bool branch_taken_0x1e8d24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e8d24) {
            ctx->pc = 0x1E8D34u;
            goto label_1e8d34;
        }
    }
    ctx->pc = 0x1E8D2Cu;
    // 0x1e8d2c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1E8D2Cu;
    {
        const bool branch_taken_0x1e8d2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8d2c) {
            ctx->pc = 0x1E8D48u;
            goto label_1e8d48;
        }
    }
    ctx->pc = 0x1E8D34u;
label_1e8d34:
    // 0x1e8d34: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e8d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8d38: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e8d38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e8d3c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e8d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e8d40: 0x1000ffd4  b           . + 4 + (-0x2C << 2)
    ctx->pc = 0x1E8D40u;
    {
        const bool branch_taken_0x1e8d40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8d40) {
            ctx->pc = 0x1E8C94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e8c94;
        }
    }
    ctx->pc = 0x1E8D48u;
label_1e8d48:
    // 0x1e8d48: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e8d48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8d4c: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e8d4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e8d50: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8D50u;
    {
        const bool branch_taken_0x1e8d50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8d50) {
            ctx->pc = 0x1E8D78u;
            goto label_1e8d78;
        }
    }
    ctx->pc = 0x1E8D58u;
    // 0x1e8d58: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8D58u;
    SET_GPR_U32(ctx, 31, 0x1E8D60u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8D60u; }
        if (ctx->pc != 0x1E8D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8D60u; }
        if (ctx->pc != 0x1E8D60u) { return; }
    }
    ctx->pc = 0x1E8D60u;
label_1e8d60:
    // 0x1e8d60: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8d60u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8d64: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e8d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e8d68: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8d68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8d6c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8d70: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1E8D70u;
    {
        const bool branch_taken_0x1e8d70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8d70) {
            ctx->pc = 0x1E8E14u;
            goto label_1e8e14;
        }
    }
    ctx->pc = 0x1E8D78u;
label_1e8d78:
    // 0x1e8d78: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e8d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e8d7c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8d7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8d80: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e8d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8d84: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8d88: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8d88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8d8c: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e8d90: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8d94: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e8d94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e8d98: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e8d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8d9c: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1e8d9cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e8da0: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8da0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8da4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e8da4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8da8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e8da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e8dac: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e8dacu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8db0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e8db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8db4: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e8db4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e8db8: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e8db8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8dbc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e8dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8dc0: 0x97c20014  lhu         $v0, 0x14($fp)
    ctx->pc = 0x1e8dc0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e8dc4: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1e8dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
    // 0x1e8dc8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e8dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8dcc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e8dccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e8dd0: 0xac62001c  sw          $v0, 0x1C($v1)
    ctx->pc = 0x1e8dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 2));
    // 0x1e8dd4: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e8dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e8dd8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e8dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e8ddc: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8ddcu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8de0: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e8de0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e8de4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e8de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8de8: 0x94420020  lhu         $v0, 0x20($v0)
    ctx->pc = 0x1e8de8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1e8dec: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e8decu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8df0: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1e8df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e8df4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e8df4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e8df8: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1e8df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1e8dfc: 0xa8620007  swl         $v0, 0x7($v1)
    ctx->pc = 0x1e8dfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1e8e00: 0xb8620004  swr         $v0, 0x4($v1)
    ctx->pc = 0x1e8e00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1e8e04: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e8e04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8e08: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1e8e08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e8e0c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8e10: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e8e10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e8e14:
    // 0x1e8e14: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8e14u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8e18: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e8e18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e8e1c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e8e1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e8e20: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e8e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e8e24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8E24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E88D8u: goto label_1e88d8;
            case 0x1E88F0u: goto label_1e88f0;
            case 0x1E8940u: goto label_1e8940;
            case 0x1E8954u: goto label_1e8954;
            case 0x1E8958u: goto label_1e8958;
            case 0x1E8990u: goto label_1e8990;
            case 0x1E89A8u: goto label_1e89a8;
            case 0x1E89C0u: goto label_1e89c0;
            case 0x1E89D8u: goto label_1e89d8;
            case 0x1E89F4u: goto label_1e89f4;
            case 0x1E8A0Cu: goto label_1e8a0c;
            case 0x1E8A28u: goto label_1e8a28;
            case 0x1E8A40u: goto label_1e8a40;
            case 0x1E8A68u: goto label_1e8a68;
            case 0x1E8A84u: goto label_1e8a84;
            case 0x1E8A94u: goto label_1e8a94;
            case 0x1E8AE8u: goto label_1e8ae8;
            case 0x1E8B00u: goto label_1e8b00;
            case 0x1E8B18u: goto label_1e8b18;
            case 0x1E8B30u: goto label_1e8b30;
            case 0x1E8B3Cu: goto label_1e8b3c;
            case 0x1E8B54u: goto label_1e8b54;
            case 0x1E8B6Cu: goto label_1e8b6c;
            case 0x1E8B9Cu: goto label_1e8b9c;
            case 0x1E8BB4u: goto label_1e8bb4;
            case 0x1E8BC8u: goto label_1e8bc8;
            case 0x1E8BF0u: goto label_1e8bf0;
            case 0x1E8C08u: goto label_1e8c08;
            case 0x1E8C2Cu: goto label_1e8c2c;
            case 0x1E8C44u: goto label_1e8c44;
            case 0x1E8C5Cu: goto label_1e8c5c;
            case 0x1E8C74u: goto label_1e8c74;
            case 0x1E8C88u: goto label_1e8c88;
            case 0x1E8C90u: goto label_1e8c90;
            case 0x1E8C94u: goto label_1e8c94;
            case 0x1E8CACu: goto label_1e8cac;
            case 0x1E8D00u: goto label_1e8d00;
            case 0x1E8D34u: goto label_1e8d34;
            case 0x1E8D48u: goto label_1e8d48;
            case 0x1E8D60u: goto label_1e8d60;
            case 0x1E8D78u: goto label_1e8d78;
            case 0x1E8E14u: goto label_1e8e14;
            case 0x1E8E4Cu: goto label_1e8e4c;
            case 0x1E8E5Cu: goto label_1e8e5c;
            case 0x1E8E74u: goto label_1e8e74;
            case 0x1E8E8Cu: goto label_1e8e8c;
            case 0x1E8EA8u: goto label_1e8ea8;
            case 0x1E8EC0u: goto label_1e8ec0;
            case 0x1E8EE0u: goto label_1e8ee0;
            case 0x1E8EFCu: goto label_1e8efc;
            case 0x1E8F18u: goto label_1e8f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8E2Cu;
    // 0x1e8e2c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e8e2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e8e30: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e8e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e8e34: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e8e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e8e38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8e38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8e3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8e40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8e40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8e44: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8E44u;
    SET_GPR_U32(ctx, 31, 0x1E8E4Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E4Cu; }
        if (ctx->pc != 0x1E8E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E4Cu; }
        if (ctx->pc != 0x1E8E4Cu) { return; }
    }
    ctx->pc = 0x1E8E4Cu;
label_1e8e4c:
    // 0x1e8e4c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8e50: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e8e50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8e54: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E8E54u;
    SET_GPR_U32(ctx, 31, 0x1E8E5Cu);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E5Cu; }
        if (ctx->pc != 0x1E8E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E5Cu; }
        if (ctx->pc != 0x1E8E5Cu) { return; }
    }
    ctx->pc = 0x1E8E5Cu;
label_1e8e5c:
    // 0x1e8e5c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e8e60: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8e64: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8E64u;
    {
        const bool branch_taken_0x1e8e64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8e64) {
            ctx->pc = 0x1E8E8Cu;
            goto label_1e8e8c;
        }
    }
    ctx->pc = 0x1E8E6Cu;
    // 0x1e8e6c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8E6Cu;
    SET_GPR_U32(ctx, 31, 0x1E8E74u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E74u; }
        if (ctx->pc != 0x1E8E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8E74u; }
        if (ctx->pc != 0x1E8E74u) { return; }
    }
    ctx->pc = 0x1E8E74u;
label_1e8e74:
    // 0x1e8e74: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8e74u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8e78: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8e7c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8e80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8e84: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1E8E84u;
    {
        const bool branch_taken_0x1e8e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8e84) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8E8Cu;
label_1e8e8c:
    // 0x1e8e8c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8e90: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8e90u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8e94: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8e94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8e98: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8E98u;
    {
        const bool branch_taken_0x1e8e98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8e98) {
            ctx->pc = 0x1E8EC0u;
            goto label_1e8ec0;
        }
    }
    ctx->pc = 0x1E8EA0u;
    // 0x1e8ea0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8EA0u;
    SET_GPR_U32(ctx, 31, 0x1E8EA8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EA8u; }
        if (ctx->pc != 0x1E8EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EA8u; }
        if (ctx->pc != 0x1E8EA8u) { return; }
    }
    ctx->pc = 0x1E8EA8u;
label_1e8ea8:
    // 0x1e8ea8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8ea8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8eac: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8eb0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8eb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8eb4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8eb8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E8EB8u;
    {
        const bool branch_taken_0x1e8eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8eb8) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8EC0u;
label_1e8ec0:
    // 0x1e8ec0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8ec4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8ec8: 0x94420020  lhu         $v0, 0x20($v0)
    ctx->pc = 0x1e8ec8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1e8ecc: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x1e8eccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1e8ed0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e8ed0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ed4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e8ed4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8ed8: 0xc075ee0  jal         func_1D7B80
    ctx->pc = 0x1E8ED8u;
    SET_GPR_U32(ctx, 31, 0x1E8EE0u);
    ctx->pc = 0x1D7B80u;
    if (runtime->hasFunction(0x1D7B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EE0u; }
        if (ctx->pc != 0x1E8EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B80_0x1d7b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8EE0u; }
        if (ctx->pc != 0x1E8EE0u) { return; }
    }
    ctx->pc = 0x1E8EE0u;
label_1e8ee0:
    // 0x1e8ee0: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ee0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8ee4: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ee4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8ee8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E8EE8u;
    {
        const bool branch_taken_0x1e8ee8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e8ee8) {
            ctx->pc = 0x1E8EFCu;
            goto label_1e8efc;
        }
    }
    ctx->pc = 0x1E8EF0u;
    // 0x1e8ef0: 0x87c20008  lh          $v0, 0x8($fp)
    ctx->pc = 0x1e8ef0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8ef4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1E8EF4u;
    {
        const bool branch_taken_0x1e8ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8ef4) {
            ctx->pc = 0x1E8F18u;
            goto label_1e8f18;
        }
    }
    ctx->pc = 0x1E8EFCu;
label_1e8efc:
    // 0x1e8efc: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8efcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8f00: 0x24020ff5  addiu       $v0, $zero, 0xFF5
    ctx->pc = 0x1e8f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4085));
    // 0x1e8f04: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e8f04u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8f08: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e8f08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8f0c: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e8f0cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8f10: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e8f10u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e8f14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e8f14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e8f18:
    // 0x1e8f18: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8f18u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8f1c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e8f1cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e8f20: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e8f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e8f24: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e8f24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e8f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E88D8u: goto label_1e88d8;
            case 0x1E88F0u: goto label_1e88f0;
            case 0x1E8940u: goto label_1e8940;
            case 0x1E8954u: goto label_1e8954;
            case 0x1E8958u: goto label_1e8958;
            case 0x1E8990u: goto label_1e8990;
            case 0x1E89A8u: goto label_1e89a8;
            case 0x1E89C0u: goto label_1e89c0;
            case 0x1E89D8u: goto label_1e89d8;
            case 0x1E89F4u: goto label_1e89f4;
            case 0x1E8A0Cu: goto label_1e8a0c;
            case 0x1E8A28u: goto label_1e8a28;
            case 0x1E8A40u: goto label_1e8a40;
            case 0x1E8A68u: goto label_1e8a68;
            case 0x1E8A84u: goto label_1e8a84;
            case 0x1E8A94u: goto label_1e8a94;
            case 0x1E8AE8u: goto label_1e8ae8;
            case 0x1E8B00u: goto label_1e8b00;
            case 0x1E8B18u: goto label_1e8b18;
            case 0x1E8B30u: goto label_1e8b30;
            case 0x1E8B3Cu: goto label_1e8b3c;
            case 0x1E8B54u: goto label_1e8b54;
            case 0x1E8B6Cu: goto label_1e8b6c;
            case 0x1E8B9Cu: goto label_1e8b9c;
            case 0x1E8BB4u: goto label_1e8bb4;
            case 0x1E8BC8u: goto label_1e8bc8;
            case 0x1E8BF0u: goto label_1e8bf0;
            case 0x1E8C08u: goto label_1e8c08;
            case 0x1E8C2Cu: goto label_1e8c2c;
            case 0x1E8C44u: goto label_1e8c44;
            case 0x1E8C5Cu: goto label_1e8c5c;
            case 0x1E8C74u: goto label_1e8c74;
            case 0x1E8C88u: goto label_1e8c88;
            case 0x1E8C90u: goto label_1e8c90;
            case 0x1E8C94u: goto label_1e8c94;
            case 0x1E8CACu: goto label_1e8cac;
            case 0x1E8D00u: goto label_1e8d00;
            case 0x1E8D34u: goto label_1e8d34;
            case 0x1E8D48u: goto label_1e8d48;
            case 0x1E8D60u: goto label_1e8d60;
            case 0x1E8D78u: goto label_1e8d78;
            case 0x1E8E14u: goto label_1e8e14;
            case 0x1E8E4Cu: goto label_1e8e4c;
            case 0x1E8E5Cu: goto label_1e8e5c;
            case 0x1E8E74u: goto label_1e8e74;
            case 0x1E8E8Cu: goto label_1e8e8c;
            case 0x1E8EA8u: goto label_1e8ea8;
            case 0x1E8EC0u: goto label_1e8ec0;
            case 0x1E8EE0u: goto label_1e8ee0;
            case 0x1E8EFCu: goto label_1e8efc;
            case 0x1E8F18u: goto label_1e8f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8F30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
