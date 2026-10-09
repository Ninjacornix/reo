#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3A90
// Address: 0x1e3a90 - 0x1e3bd0
void sub_001E3A90_0x1e3a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3A90_0x1e3a90");
#endif

    switch (ctx->pc) {
        case 0x1e3b40u: goto label_1e3b40;
        case 0x1e3b84u: goto label_1e3b84;
        case 0x1e3bb4u: goto label_1e3bb4;
        default: break;
    }

    ctx->pc = 0x1e3a90u;

    // 0x1e3a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e3a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e3a94: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e3a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e3a98: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e3a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e3a9c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3a9cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3aa0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3aa4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3aa8: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3aac: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ab0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3ab4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3AB4u;
    {
        const bool branch_taken_0x1e3ab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3ab4) {
            ctx->pc = 0x1E3ADCu;
            goto label_1e3adc;
        }
    }
    ctx->pc = 0x1E3ABCu;
    // 0x1e3abc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ac0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3ac4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3ac8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3acc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3ad0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3ad4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3AD4u;
    {
        const bool branch_taken_0x1e3ad4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ad4) {
            ctx->pc = 0x1E3AF0u;
            goto label_1e3af0;
        }
    }
    ctx->pc = 0x1E3ADCu;
label_1e3adc:
    // 0x1e3adc: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3ae0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3ae4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3ae8: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1E3AE8u;
    {
        const bool branch_taken_0x1e3ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ae8) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3AF0u;
label_1e3af0:
    // 0x1e3af0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3af0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3af4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3af4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3af8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3af8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3afc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3b00: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3b04: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3b08: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3b08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3b0c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b10: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3b14: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B14u;
    {
        const bool branch_taken_0x1e3b14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b14) {
            ctx->pc = 0x1E3B30u;
            goto label_1e3b30;
        }
    }
    ctx->pc = 0x1E3B1Cu;
    // 0x1e3b1c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3b20: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b20u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b28: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E3B28u;
    {
        const bool branch_taken_0x1e3b28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b28) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3B30u;
label_1e3b30:
    // 0x1e3b30: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b34: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e3b34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b38: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3B38u;
    SET_GPR_U32(ctx, 31, 0x1E3B40u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B40u; }
        if (ctx->pc != 0x1E3B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B40u; }
        if (ctx->pc != 0x1E3B40u) { return; }
    }
    ctx->pc = 0x1E3B40u;
label_1e3b40:
    // 0x1e3b40: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e3b40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e3b44: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e3b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3b48: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B48u;
    {
        const bool branch_taken_0x1e3b48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b48) {
            ctx->pc = 0x1E3B64u;
            goto label_1e3b64;
        }
    }
    ctx->pc = 0x1E3B50u;
    // 0x1e3b50: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3b54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b5c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E3B5Cu;
    {
        const bool branch_taken_0x1e3b5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b5c) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3B64u;
label_1e3b64:
    // 0x1e3b64: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3b64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b68: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3b68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3b6c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3b6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3b70: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e3b70u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b74: 0x2408000e  addiu       $t0, $zero, 0xE
    ctx->pc = 0x1e3b74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e3b78: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3b78u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b7c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3B7Cu;
    SET_GPR_U32(ctx, 31, 0x1E3B84u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B84u; }
        if (ctx->pc != 0x1E3B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B84u; }
        if (ctx->pc != 0x1E3B84u) { return; }
    }
    ctx->pc = 0x1E3B84u;
label_1e3b84:
    // 0x1e3b84: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B84u;
    {
        const bool branch_taken_0x1e3b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b84) {
            ctx->pc = 0x1E3BA0u;
            goto label_1e3ba0;
        }
    }
    ctx->pc = 0x1E3B8Cu;
    // 0x1e3b8c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3b90: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b90u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b94: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3B98u;
    {
        const bool branch_taken_0x1e3b98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b98) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3BA0u;
label_1e3ba0:
    // 0x1e3ba0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ba4: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x1e3ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1e3ba8: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e3ba8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3bac: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3BACu;
    SET_GPR_U32(ctx, 31, 0x1E3BB4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3BB4u; }
        if (ctx->pc != 0x1E3BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3BB4u; }
        if (ctx->pc != 0x1E3BB4u) { return; }
    }
    ctx->pc = 0x1E3BB4u;
label_1e3bb4:
    // 0x1e3bb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3bb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3bb8:
    // 0x1e3bb8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3bb8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3bbc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e3bbcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e3bc0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e3bc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e3bc4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e3bc4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e3bc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3BC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3BD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
