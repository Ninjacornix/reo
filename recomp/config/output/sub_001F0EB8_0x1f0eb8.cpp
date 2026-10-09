#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0EB8
// Address: 0x1f0eb8 - 0x1f105c
void sub_001F0EB8_0x1f0eb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0EB8_0x1f0eb8");
#endif

    switch (ctx->pc) {
        case 0x1f1004u: goto label_1f1004;
        case 0x1f1030u: goto label_1f1030;
        default: break;
    }

    ctx->pc = 0x1f0eb8u;

    // 0x1f0eb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f0eb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f0ebc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f0ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f0ec0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0ec0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ec4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0ec8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f0ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f0ecc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f0eccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f0ed0: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1f0ed0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1f0ed4: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1f0ed4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1f0ed8: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1f0ed8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1f0edc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0edcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0ee0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f0ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0ee4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1f0ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1f0ee8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f0ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f0eec: 0x18400011  blez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1F0EECu;
    {
        const bool branch_taken_0x1f0eec = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1f0eec) {
            ctx->pc = 0x1F0F34u;
            goto label_1f0f34;
        }
    }
    ctx->pc = 0x1F0EF4u;
    // 0x1f0ef4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f0ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0ef8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F0EF8u;
    {
        const bool branch_taken_0x1f0ef8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0ef8) {
            ctx->pc = 0x1F0F18u;
            goto label_1f0f18;
        }
    }
    ctx->pc = 0x1F0F00u;
    // 0x1f0f00: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0f00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0f04: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1f0f04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0f08: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1f0f08u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f0f0c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0f10: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1F0F10u;
    {
        const bool branch_taken_0x1f0f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f10) {
            ctx->pc = 0x1F0F44u;
            goto label_1f0f44;
        }
    }
    ctx->pc = 0x1F0F18u;
label_1f0f18:
    // 0x1f0f18: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f0f18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0f1c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f0f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0f20: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1f0f20u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0f24: 0x24420022  addiu       $v0, $v0, 0x22
    ctx->pc = 0x1f0f24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 34));
    // 0x1f0f28: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0f2c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F0F2Cu;
    {
        const bool branch_taken_0x1f0f2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f2c) {
            ctx->pc = 0x1F0F44u;
            goto label_1f0f44;
        }
    }
    ctx->pc = 0x1F0F34u;
label_1f0f34:
    // 0x1f0f34: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0f34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0f38: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f0f38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f0f3c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1f0f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f0f40: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
label_1f0f44:
    // 0x1f0f44: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0f48: 0x28420011  slti        $v0, $v0, 0x11
    ctx->pc = 0x1f0f48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x1f0f4c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0F4Cu;
    {
        const bool branch_taken_0x1f0f4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f4c) {
            ctx->pc = 0x1F0F5Cu;
            goto label_1f0f5c;
        }
    }
    ctx->pc = 0x1F0F54u;
    // 0x1f0f54: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x1f0f54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1f0f58: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
label_1f0f5c:
    // 0x1f0f5c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0f60: 0x28427d01  slti        $v0, $v0, 0x7D01
    ctx->pc = 0x1f0f60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32001) ? 1 : 0);
    // 0x1f0f64: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F0F64u;
    {
        const bool branch_taken_0x1f0f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f64) {
            ctx->pc = 0x1F0F74u;
            goto label_1f0f74;
        }
    }
    ctx->pc = 0x1F0F6Cu;
    // 0x1f0f6c: 0x24027d00  addiu       $v0, $zero, 0x7D00
    ctx->pc = 0x1f0f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32000));
    // 0x1f0f70: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0f70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
label_1f0f74:
    // 0x1f0f74: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1f0f74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0f78: 0x18400010  blez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1F0F78u;
    {
        const bool branch_taken_0x1f0f78 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1f0f78) {
            ctx->pc = 0x1F0FBCu;
            goto label_1f0fbc;
        }
    }
    ctx->pc = 0x1F0F80u;
    // 0x1f0f80: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1f0f80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0f84: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1f0f84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0f88: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1f0f88u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1f0f8c: 0x1812  mflo        $v1
    ctx->pc = 0x1f0f8cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1f0f90: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1F0F90u;
    {
        const bool branch_taken_0x1f0f90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f90) {
            ctx->pc = 0x1F0F94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1F0F90u;
            // 0x1f0f94: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1F0F98u;
            goto label_1f0f98;
        }
    }
    ctx->pc = 0x1F0F98u;
label_1f0f98:
    // 0x1f0f98: 0x2862000b  slti        $v0, $v1, 0xB
    ctx->pc = 0x1f0f98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x1f0f9c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F0F9Cu;
    {
        const bool branch_taken_0x1f0f9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f0f9c) {
            ctx->pc = 0x1F0FBCu;
            goto label_1f0fbc;
        }
    }
    ctx->pc = 0x1F0FA4u;
    // 0x1f0fa4: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1f0fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f0fa8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1f0fa8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0fac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1f0facu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1f0fb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f0fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f0fb4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1f0fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1f0fb8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
label_1f0fbc:
    // 0x1f0fbc: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f0fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0fc0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0fc4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f0fc8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0fc8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0fcc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f0fccu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f0fd0: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f0fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f0fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0F18u: goto label_1f0f18;
            case 0x1F0F34u: goto label_1f0f34;
            case 0x1F0F44u: goto label_1f0f44;
            case 0x1F0F5Cu: goto label_1f0f5c;
            case 0x1F0F74u: goto label_1f0f74;
            case 0x1F0F98u: goto label_1f0f98;
            case 0x1F0FBCu: goto label_1f0fbc;
            case 0x1F1004u: goto label_1f1004;
            case 0x1F1020u: goto label_1f1020;
            case 0x1F1030u: goto label_1f1030;
            case 0x1F1044u: goto label_1f1044;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0FDCu;
    // 0x1f0fdc: 0x0  nop
    ctx->pc = 0x1f0fdcu;
    // NOP
    // 0x1f0fe0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f0fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f0fe4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f0fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f0fe8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f0fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f0fec: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0fecu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ff0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0ff4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f0ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f0ff8: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x1f0ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f0ffc: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1F0FFCu;
    SET_GPR_U32(ctx, 31, 0x1F1004u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1004u; }
        if (ctx->pc != 0x1F1004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1004u; }
        if (ctx->pc != 0x1F1004u) { return; }
    }
    ctx->pc = 0x1F1004u;
label_1f1004:
    // 0x1f1004: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f1004u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f1008: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f100c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F100Cu;
    {
        const bool branch_taken_0x1f100c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f100c) {
            ctx->pc = 0x1F1020u;
            goto label_1f1020;
        }
    }
    ctx->pc = 0x1F1014u;
    // 0x1f1014: 0x2402e4a9  addiu       $v0, $zero, -0x1B57
    ctx->pc = 0x1f1014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960297));
    // 0x1f1018: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F1018u;
    {
        const bool branch_taken_0x1f1018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1018) {
            ctx->pc = 0x1F1044u;
            goto label_1f1044;
        }
    }
    ctx->pc = 0x1F1020u;
label_1f1020:
    // 0x1f1020: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f1020u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1024: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f1024u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1028: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1F1028u;
    SET_GPR_U32(ctx, 31, 0x1F1030u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1030u; }
        if (ctx->pc != 0x1F1030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1030u; }
        if (ctx->pc != 0x1F1030u) { return; }
    }
    ctx->pc = 0x1F1030u;
label_1f1030:
    // 0x1f1030: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1030u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1034: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f1034u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1038: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f103c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f103cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1040: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f1044:
    // 0x1f1044: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1044u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1048: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f1048u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f104c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f104cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f1050: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1054: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0F18u: goto label_1f0f18;
            case 0x1F0F34u: goto label_1f0f34;
            case 0x1F0F44u: goto label_1f0f44;
            case 0x1F0F5Cu: goto label_1f0f5c;
            case 0x1F0F74u: goto label_1f0f74;
            case 0x1F0F98u: goto label_1f0f98;
            case 0x1F0FBCu: goto label_1f0fbc;
            case 0x1F1004u: goto label_1f1004;
            case 0x1F1020u: goto label_1f1020;
            case 0x1F1030u: goto label_1f1030;
            case 0x1F1044u: goto label_1f1044;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F105Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
