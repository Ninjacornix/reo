#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3BD0
// Address: 0x1e3bd0 - 0x1e3d18
void sub_001E3BD0_0x1e3bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3BD0_0x1e3bd0");
#endif

    switch (ctx->pc) {
        case 0x1e3c80u: goto label_1e3c80;
        case 0x1e3cc4u: goto label_1e3cc4;
        case 0x1e3cfcu: goto label_1e3cfc;
        default: break;
    }

    ctx->pc = 0x1e3bd0u;

    // 0x1e3bd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3bd4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3bd8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3bdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3bdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3be0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3be0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3be4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3be4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3be8: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3be8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3bec: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3becu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3bf0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3bf4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3BF4u;
    {
        const bool branch_taken_0x1e3bf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3bf4) {
            ctx->pc = 0x1E3C1Cu;
            goto label_1e3c1c;
        }
    }
    ctx->pc = 0x1E3BFCu;
    // 0x1e3bfc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3c00: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3c00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3c04: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3c04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3c08: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3c0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3c10: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3c14: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C14u;
    {
        const bool branch_taken_0x1e3c14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c14) {
            ctx->pc = 0x1E3C30u;
            goto label_1e3c30;
        }
    }
    ctx->pc = 0x1E3C1Cu;
label_1e3c1c:
    // 0x1e3c1c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3c20: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c20u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c28: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1E3C28u;
    {
        const bool branch_taken_0x1e3c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c28) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3C30u;
label_1e3c30:
    // 0x1e3c30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3c34: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3c34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3c38: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3c38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3c3c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3c40: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3c40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3c44: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3c44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3c48: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3c48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3c4c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3c50: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3c50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3c54: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C54u;
    {
        const bool branch_taken_0x1e3c54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c54) {
            ctx->pc = 0x1E3C70u;
            goto label_1e3c70;
        }
    }
    ctx->pc = 0x1E3C5Cu;
    // 0x1e3c5c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3c60: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c60u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c68: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1E3C68u;
    {
        const bool branch_taken_0x1e3c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c68) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3C70u;
label_1e3c70:
    // 0x1e3c70: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3c70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3c74: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e3c74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3c78: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3C78u;
    SET_GPR_U32(ctx, 31, 0x1E3C80u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3C80u; }
        if (ctx->pc != 0x1E3C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3C80u; }
        if (ctx->pc != 0x1E3C80u) { return; }
    }
    ctx->pc = 0x1E3C80u;
label_1e3c80:
    // 0x1e3c80: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e3c80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e3c84: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e3c84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3c88: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C88u;
    {
        const bool branch_taken_0x1e3c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c88) {
            ctx->pc = 0x1E3CA4u;
            goto label_1e3ca4;
        }
    }
    ctx->pc = 0x1E3C90u;
    // 0x1e3c90: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3c94: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c94u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c98: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c9c: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E3C9Cu;
    {
        const bool branch_taken_0x1e3c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c9c) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3CA4u;
label_1e3ca4:
    // 0x1e3ca4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3ca8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3cac: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3cacu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3cb0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e3cb0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3cb4: 0x24080047  addiu       $t0, $zero, 0x47
    ctx->pc = 0x1e3cb4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x1e3cb8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3cb8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3cbc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3CBCu;
    SET_GPR_U32(ctx, 31, 0x1E3CC4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CC4u; }
        if (ctx->pc != 0x1E3CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CC4u; }
        if (ctx->pc != 0x1E3CC4u) { return; }
    }
    ctx->pc = 0x1E3CC4u;
label_1e3cc4:
    // 0x1e3cc4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3cc8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3ccc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3CCCu;
    {
        const bool branch_taken_0x1e3ccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ccc) {
            ctx->pc = 0x1E3CE8u;
            goto label_1e3ce8;
        }
    }
    ctx->pc = 0x1E3CD4u;
    // 0x1e3cd4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3cd8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3cdc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3cdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3ce0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3CE0u;
    {
        const bool branch_taken_0x1e3ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ce0) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3CE8u;
label_1e3ce8:
    // 0x1e3ce8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3cec: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1e3cecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1e3cf0: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e3cf0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3cf4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3CF4u;
    SET_GPR_U32(ctx, 31, 0x1E3CFCu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CFCu; }
        if (ctx->pc != 0x1E3CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CFCu; }
        if (ctx->pc != 0x1E3CFCu) { return; }
    }
    ctx->pc = 0x1E3CFCu;
label_1e3cfc:
    // 0x1e3cfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3cfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3d00:
    // 0x1e3d00: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3d00u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3d04: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3d04u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3d08: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3d0c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3d0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3d10: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3D10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3D18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
