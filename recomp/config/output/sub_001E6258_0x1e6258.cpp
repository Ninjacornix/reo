#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E6258
// Address: 0x1e6258 - 0x1e6328
void sub_001E6258_0x1e6258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E6258_0x1e6258");
#endif

    switch (ctx->pc) {
        case 0x1e630cu: goto label_1e630c;
        default: break;
    }

    ctx->pc = 0x1e6258u;

    // 0x1e6258: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e625c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e625cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6260: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6264: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6264u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6268: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6268u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e626c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e626cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6270: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e6270u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e6274: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6274u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6278: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e627c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E627Cu;
    {
        const bool branch_taken_0x1e627c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e627c) {
            ctx->pc = 0x1E62A4u;
            goto label_1e62a4;
        }
    }
    ctx->pc = 0x1E6284u;
    // 0x1e6284: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6284u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6288: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6288u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e628c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e628cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6290: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6294: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6298: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e629c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E629Cu;
    {
        const bool branch_taken_0x1e629c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e629c) {
            ctx->pc = 0x1E62B8u;
            goto label_1e62b8;
        }
    }
    ctx->pc = 0x1E62A4u;
label_1e62a4:
    // 0x1e62a4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e62a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e62a8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e62a8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e62ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e62acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e62b0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E62B0u;
    {
        const bool branch_taken_0x1e62b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62b0) {
            ctx->pc = 0x1E6310u;
            goto label_1e6310;
        }
    }
    ctx->pc = 0x1E62B8u;
label_1e62b8:
    // 0x1e62b8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e62b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e62bc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e62bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e62c0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e62c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e62c4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e62c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e62c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e62c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e62cc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e62ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e62d0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e62d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e62d4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e62d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e62d8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e62d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e62dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E62DCu;
    {
        const bool branch_taken_0x1e62dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62dc) {
            ctx->pc = 0x1E62F8u;
            goto label_1e62f8;
        }
    }
    ctx->pc = 0x1E62E4u;
    // 0x1e62e4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e62e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e62e8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e62e8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e62ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e62ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e62f0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E62F0u;
    {
        const bool branch_taken_0x1e62f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62f0) {
            ctx->pc = 0x1E6310u;
            goto label_1e6310;
        }
    }
    ctx->pc = 0x1E62F8u;
label_1e62f8:
    // 0x1e62f8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e62f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e62fc: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e62fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e6300: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e6300u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6304: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6304u;
    SET_GPR_U32(ctx, 31, 0x1E630Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E630Cu; }
        if (ctx->pc != 0x1E630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E630Cu; }
        if (ctx->pc != 0x1E630Cu) { return; }
    }
    ctx->pc = 0x1E630Cu;
label_1e630c:
    // 0x1e630c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e630cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6310:
    // 0x1e6310: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6310u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6314: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e6314u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e6318: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e6318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e631c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e631cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e6320: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6328u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
