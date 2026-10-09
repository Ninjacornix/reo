#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E6188
// Address: 0x1e6188 - 0x1e6258
void sub_001E6188_0x1e6188(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E6188_0x1e6188");
#endif

    switch (ctx->pc) {
        case 0x1e623cu: goto label_1e623c;
        default: break;
    }

    ctx->pc = 0x1e6188u;

    // 0x1e6188: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6188u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e618c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e618cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6190: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6190u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6194: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6194u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6198: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e619c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e619cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e61a0: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e61a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e61a4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e61a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e61a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e61ac: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E61ACu;
    {
        const bool branch_taken_0x1e61ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e61ac) {
            ctx->pc = 0x1E61D4u;
            goto label_1e61d4;
        }
    }
    ctx->pc = 0x1E61B4u;
    // 0x1e61b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e61b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e61b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e61bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e61bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e61c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e61c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e61c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e61c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e61c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e61c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e61cc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E61CCu;
    {
        const bool branch_taken_0x1e61cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e61cc) {
            ctx->pc = 0x1E61E8u;
            goto label_1e61e8;
        }
    }
    ctx->pc = 0x1E61D4u;
label_1e61d4:
    // 0x1e61d4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e61d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e61d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e61d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e61dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e61dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e61e0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E61E0u;
    {
        const bool branch_taken_0x1e61e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e61e0) {
            ctx->pc = 0x1E6240u;
            goto label_1e6240;
        }
    }
    ctx->pc = 0x1E61E8u;
label_1e61e8:
    // 0x1e61e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e61e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61ec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e61ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e61f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e61f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e61f4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e61f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e61f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e61f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e61fc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e61fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6200: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e6200u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e6204: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e6204u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6208: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6208u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e620c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E620Cu;
    {
        const bool branch_taken_0x1e620c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e620c) {
            ctx->pc = 0x1E6228u;
            goto label_1e6228;
        }
    }
    ctx->pc = 0x1E6214u;
    // 0x1e6214: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6218: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6218u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e621c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e621cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6220: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6220u;
    {
        const bool branch_taken_0x1e6220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6220) {
            ctx->pc = 0x1E6240u;
            goto label_1e6240;
        }
    }
    ctx->pc = 0x1E6228u;
label_1e6228:
    // 0x1e6228: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6228u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e622c: 0x2405002b  addiu       $a1, $zero, 0x2B
    ctx->pc = 0x1e622cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x1e6230: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e6230u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6234: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6234u;
    SET_GPR_U32(ctx, 31, 0x1E623Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E623Cu; }
        if (ctx->pc != 0x1E623Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E623Cu; }
        if (ctx->pc != 0x1E623Cu) { return; }
    }
    ctx->pc = 0x1E623Cu;
label_1e623c:
    // 0x1e623c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e623cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6240:
    // 0x1e6240: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6240u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6244: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e6244u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e6248: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e6248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e624c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e624cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e6250: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6258u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
