#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E2EAC
// Address: 0x1e2eac - 0x1e300c
void sub_001E2EAC_0x1e2eac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E2EAC_0x1e2eac");
#endif

    switch (ctx->pc) {
        case 0x1e2f5cu: goto label_1e2f5c;
        case 0x1e2fa8u: goto label_1e2fa8;
        case 0x1e2fd8u: goto label_1e2fd8;
        default: break;
    }

    ctx->pc = 0x1e2eacu;

    // 0x1e2eac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2eacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2eb0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2eb4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2eb8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2eb8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2ebc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2ec0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2ec4: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e2ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e2ec8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2ecc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2ed0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2ED0u;
    {
        const bool branch_taken_0x1e2ed0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2ed0) {
            ctx->pc = 0x1E2EF8u;
            goto label_1e2ef8;
        }
    }
    ctx->pc = 0x1E2ED8u;
    // 0x1e2ed8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2edc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2edcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2ee0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2ee4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2ee8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2eec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2eecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2ef0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2EF0u;
    {
        const bool branch_taken_0x1e2ef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ef0) {
            ctx->pc = 0x1E2F0Cu;
            goto label_1e2f0c;
        }
    }
    ctx->pc = 0x1E2EF8u;
label_1e2ef8:
    // 0x1e2ef8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2efc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2efcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f04: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E2F04u;
    {
        const bool branch_taken_0x1e2f04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f04) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F0Cu;
label_1e2f0c:
    // 0x1e2f0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2f10: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2f10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2f14: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2f14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2f18: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2f1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2f20: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2f24: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e2f28: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f2c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2f30: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2F30u;
    {
        const bool branch_taken_0x1e2f30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f30) {
            ctx->pc = 0x1E2F4Cu;
            goto label_1e2f4c;
        }
    }
    ctx->pc = 0x1E2F38u;
    // 0x1e2f38: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2f3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f44: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1E2F44u;
    {
        const bool branch_taken_0x1e2f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f44) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F4Cu;
label_1e2f4c:
    // 0x1e2f4c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f50: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e2f50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2f54: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2F54u;
    SET_GPR_U32(ctx, 31, 0x1E2F5Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2F5Cu; }
        if (ctx->pc != 0x1E2F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2F5Cu; }
        if (ctx->pc != 0x1E2F5Cu) { return; }
    }
    ctx->pc = 0x1E2F5Cu;
label_1e2f5c:
    // 0x1e2f5c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e2f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e2f60: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2f64: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2F64u;
    {
        const bool branch_taken_0x1e2f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f64) {
            ctx->pc = 0x1E2F80u;
            goto label_1e2f80;
        }
    }
    ctx->pc = 0x1E2F6Cu;
    // 0x1e2f6c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2f70: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2f70u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f74: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f78: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E2F78u;
    {
        const bool branch_taken_0x1e2f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f78) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F80u;
label_1e2f80:
    // 0x1e2f80: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f84: 0x9042061a  lbu         $v0, 0x61A($v0)
    ctx->pc = 0x1e2f84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1562)));
    // 0x1e2f88: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2f88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f8c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2f90: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e2f90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e2f94: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e2f94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2f98: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x1e2f98u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1e2f9c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2f9cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2fa0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2FA0u;
    SET_GPR_U32(ctx, 31, 0x1E2FA8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FA8u; }
        if (ctx->pc != 0x1E2FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FA8u; }
        if (ctx->pc != 0x1E2FA8u) { return; }
    }
    ctx->pc = 0x1E2FA8u;
label_1e2fa8:
    // 0x1e2fa8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2FA8u;
    {
        const bool branch_taken_0x1e2fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2fa8) {
            ctx->pc = 0x1E2FC4u;
            goto label_1e2fc4;
        }
    }
    ctx->pc = 0x1E2FB0u;
    // 0x1e2fb0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2fb4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2fb8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2fbc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2FBCu;
    {
        const bool branch_taken_0x1e2fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2fbc) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2FC4u;
label_1e2fc4:
    // 0x1e2fc4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2fc8: 0x24050023  addiu       $a1, $zero, 0x23
    ctx->pc = 0x1e2fc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x1e2fcc: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e2fccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2fd0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2FD0u;
    SET_GPR_U32(ctx, 31, 0x1E2FD8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FD8u; }
        if (ctx->pc != 0x1E2FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FD8u; }
        if (ctx->pc != 0x1E2FD8u) { return; }
    }
    ctx->pc = 0x1E2FD8u;
label_1e2fd8:
    // 0x1e2fd8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2fdc: 0x9064061a  lbu         $a0, 0x61A($v1)
    ctx->pc = 0x1e2fdcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1562)));
    // 0x1e2fe0: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2fe4: 0xa062061a  sb          $v0, 0x61A($v1)
    ctx->pc = 0x1e2fe4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1562), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2fe8: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2fe8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2fec: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2fecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2ff0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e2ff4:
    // 0x1e2ff4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2ff4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2ff8: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2ff8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2ffc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3000: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3004: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E300Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
