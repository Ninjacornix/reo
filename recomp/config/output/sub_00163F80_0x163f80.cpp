#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163F80
// Address: 0x163f80 - 0x163fd8
void sub_00163F80_0x163f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163F80_0x163f80");
#endif

    switch (ctx->pc) {
        case 0x163facu: goto label_163fac;
        default: break;
    }

    ctx->pc = 0x163f80u;

    // 0x163f80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x163f80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x163f84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163f84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163f88: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x163f88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163f8c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163f90: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x163f90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163f94: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x163f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163f98: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x163f98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163f9c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x163f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x163fa0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x163fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x163fa4: 0xc05799e  jal         func_15E678
    ctx->pc = 0x163FA4u;
    SET_GPR_U32(ctx, 31, 0x163FACu);
    ctx->pc = 0x163FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163FA4u;
            // 0x163fa8: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163FACu; }
        if (ctx->pc != 0x163FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163FACu; }
        if (ctx->pc != 0x163FACu) { return; }
    }
    ctx->pc = 0x163FACu;
label_163fac:
    // 0x163fac: 0xac50004c  sw          $s0, 0x4C($v0)
    ctx->pc = 0x163facu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 16));
    // 0x163fb0: 0xac510040  sw          $s1, 0x40($v0)
    ctx->pc = 0x163fb0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 64), GPR_U32(ctx, 17));
    // 0x163fb4: 0xac520044  sw          $s2, 0x44($v0)
    ctx->pc = 0x163fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 68), GPR_U32(ctx, 18));
    // 0x163fb8: 0xac530048  sw          $s3, 0x48($v0)
    ctx->pc = 0x163fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 19));
    // 0x163fbc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163fbcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163fc0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163fc0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163fc4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163fc4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163fc8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x163fc8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163fcc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x163fccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x163fd0: 0x3e00008  jr          $ra
    ctx->pc = 0x163FD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163FD0u;
            // 0x163fd4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163FACu: goto label_163fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163FD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
