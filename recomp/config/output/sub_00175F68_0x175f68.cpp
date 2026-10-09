#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175F68
// Address: 0x175f68 - 0x176000
void sub_00175F68_0x175f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175F68_0x175f68");
#endif

    switch (ctx->pc) {
        case 0x175f9cu: goto label_175f9c;
        default: break;
    }

    ctx->pc = 0x175f68u;

    // 0x175f68: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x175f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x175f6c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x175f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x175f70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175f74: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x175f74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175f78: 0x24050047  addiu       $a1, $zero, 0x47
    ctx->pc = 0x175f78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x175f7c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175f80: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x175f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175f84: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x175f84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175f88: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x175f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x175f8c: 0x2453f138  addiu       $s3, $v0, -0xEC8
    ctx->pc = 0x175f8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963512));
    // 0x175f90: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x175f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x175f94: 0xc05d58a  jal         func_175628
    ctx->pc = 0x175F94u;
    SET_GPR_U32(ctx, 31, 0x175F9Cu);
    ctx->pc = 0x175F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175F94u;
            // 0x175f98: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175F9Cu; }
        if (ctx->pc != 0x175F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175F9Cu; }
        if (ctx->pc != 0x175F9Cu) { return; }
    }
    ctx->pc = 0x175F9Cu;
label_175f9c:
    // 0x175f9c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x175f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175fa0: 0x14430009  bne         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x175FA0u;
    {
        const bool branch_taken_0x175fa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x175fa0) {
            ctx->pc = 0x175FC8u;
            goto label_175fc8;
        }
    }
    ctx->pc = 0x175FA8u;
    // 0x175fa8: 0x8e02028c  lw          $v0, 0x28C($s0)
    ctx->pc = 0x175fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 652)));
    // 0x175fac: 0x8e030264  lw          $v1, 0x264($s0)
    ctx->pc = 0x175facu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 612)));
    // 0x175fb0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x175fb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x175fb4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x175fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x175fb8: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x175fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x175fbc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x175FBCu;
    {
        const bool branch_taken_0x175fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x175FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175FBCu;
            // 0x175fc0: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175fbc) {
            ctx->pc = 0x175FE0u;
            goto label_175fe0;
        }
    }
    ctx->pc = 0x175FC4u;
    // 0x175fc4: 0x0  nop
    ctx->pc = 0x175fc4u;
    // NOP
label_175fc8:
    // 0x175fc8: 0x8e020298  lw          $v0, 0x298($s0)
    ctx->pc = 0x175fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 664)));
    // 0x175fcc: 0x8e03028c  lw          $v1, 0x28C($s0)
    ctx->pc = 0x175fccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 652)));
    // 0x175fd0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x175fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x175fd4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x175fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x175fd8: 0x8e03029c  lw          $v1, 0x29C($s0)
    ctx->pc = 0x175fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 668)));
    // 0x175fdc: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x175fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_175fe0:
    // 0x175fe0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175fe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175fe4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175fe4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175fe8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x175fe8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175fec: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x175fecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175ff0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x175ff0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x175ff4: 0x3e00008  jr          $ra
    ctx->pc = 0x175FF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175FF4u;
            // 0x175ff8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175F9Cu: goto label_175f9c;
            case 0x175FC8u: goto label_175fc8;
            case 0x175FE0u: goto label_175fe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175FFCu;
    // 0x175ffc: 0x0  nop
    ctx->pc = 0x175ffcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
