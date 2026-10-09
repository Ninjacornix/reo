#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5900
// Address: 0x1e5900 - 0x1e5a28
void sub_001E5900_0x1e5900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5900_0x1e5900");
#endif

    switch (ctx->pc) {
        case 0x1e59acu: goto label_1e59ac;
        case 0x1e59f0u: goto label_1e59f0;
        default: break;
    }

    ctx->pc = 0x1e5900u;

    // 0x1e5900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e5900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e5904: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e5904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e5908: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e5908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e590c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e590cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5910: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5910u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5914: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e5914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e5918: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e591c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e591cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5920: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5920u;
    {
        const bool branch_taken_0x1e5920 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5920) {
            ctx->pc = 0x1E5948u;
            goto label_1e5948;
        }
    }
    ctx->pc = 0x1E5928u;
    // 0x1e5928: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e592c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e592cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5930: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5934: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5938: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e593c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e593cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5940: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5940u;
    {
        const bool branch_taken_0x1e5940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5940) {
            ctx->pc = 0x1E595Cu;
            goto label_1e595c;
        }
    }
    ctx->pc = 0x1E5948u;
label_1e5948:
    // 0x1e5948: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e594c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e594cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5950: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5954: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1E5954u;
    {
        const bool branch_taken_0x1e5954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5954) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E595Cu;
label_1e595c:
    // 0x1e595c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e595cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5960: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5960u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5964: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5964u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5968: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e596c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e596cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5970: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5974: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e5974u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e5978: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e597c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e597cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5980: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5980u;
    {
        const bool branch_taken_0x1e5980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5980) {
            ctx->pc = 0x1E599Cu;
            goto label_1e599c;
        }
    }
    ctx->pc = 0x1E5988u;
    // 0x1e5988: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e598c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e598cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5990: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5994: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E5994u;
    {
        const bool branch_taken_0x1e5994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5994) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E599Cu;
label_1e599c:
    // 0x1e599c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e599cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e59a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e59a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59a4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E59A4u;
    SET_GPR_U32(ctx, 31, 0x1E59ACu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59ACu; }
        if (ctx->pc != 0x1E59ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59ACu; }
        if (ctx->pc != 0x1E59ACu) { return; }
    }
    ctx->pc = 0x1E59ACu;
label_1e59ac:
    // 0x1e59ac: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e59acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e59b0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e59b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e59b4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E59B4u;
    {
        const bool branch_taken_0x1e59b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e59b4) {
            ctx->pc = 0x1E59D0u;
            goto label_1e59d0;
        }
    }
    ctx->pc = 0x1E59BCu;
    // 0x1e59bc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e59bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e59c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e59c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e59c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e59c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e59c8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E59C8u;
    {
        const bool branch_taken_0x1e59c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e59c8) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E59D0u;
label_1e59d0:
    // 0x1e59d0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e59d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e59d4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e59d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e59d8: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e59d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e59dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e59dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59e0: 0x24080013  addiu       $t0, $zero, 0x13
    ctx->pc = 0x1e59e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1e59e4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e59e4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59e8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E59E8u;
    SET_GPR_U32(ctx, 31, 0x1E59F0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59F0u; }
        if (ctx->pc != 0x1E59F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59F0u; }
        if (ctx->pc != 0x1E59F0u) { return; }
    }
    ctx->pc = 0x1E59F0u;
label_1e59f0:
    // 0x1e59f0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E59F0u;
    {
        const bool branch_taken_0x1e59f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e59f0) {
            ctx->pc = 0x1E5A0Cu;
            goto label_1e5a0c;
        }
    }
    ctx->pc = 0x1E59F8u;
    // 0x1e59f8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e59f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e59fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e59fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5a00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5a04: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5A04u;
    {
        const bool branch_taken_0x1e5a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a04) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E5A0Cu;
label_1e5a0c:
    // 0x1e5a0c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5a0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5a10:
    // 0x1e5a10: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5a10u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a14: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e5a14u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e5a18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e5a18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e5a1c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e5a1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e5a20: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5A20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5A28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
