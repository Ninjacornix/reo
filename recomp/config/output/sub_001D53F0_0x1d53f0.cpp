#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D53F0
// Address: 0x1d53f0 - 0x1d5498
void sub_001D53F0_0x1d53f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D53F0_0x1d53f0");
#endif

    switch (ctx->pc) {
        case 0x1d541cu: goto label_1d541c;
        case 0x1d5454u: goto label_1d5454;
        case 0x1d5468u: goto label_1d5468;
        default: break;
    }

    ctx->pc = 0x1d53f0u;

    // 0x1d53f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d53f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d53f4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1d53f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1d53f8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1d53f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1d53fc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d53fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d5400: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d5400u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5404: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d5404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d5408: 0x8c646998  lw          $a0, 0x6998($v1)
    ctx->pc = 0x1d5408u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 27032)));
    // 0x1d540c: 0x1082001f  beq         $a0, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1D540Cu;
    {
        const bool branch_taken_0x1d540c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D540Cu;
            // 0x1d5410: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d540c) {
            ctx->pc = 0x1D548Cu;
            goto label_1d548c;
        }
    }
    ctx->pc = 0x1D5414u;
    // 0x1d5414: 0xc045198  jal         func_114660
    ctx->pc = 0x1D5414u;
    SET_GPR_U32(ctx, 31, 0x1D541Cu);
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D541Cu; }
        if (ctx->pc != 0x1D541Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D541Cu; }
        if (ctx->pc != 0x1D541Cu) { return; }
    }
    ctx->pc = 0x1D541Cu;
label_1d541c:
    // 0x1d541c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d541cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d5420: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d5420u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d5424: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d5424u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d5428: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d5428u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d542c: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d542cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d5430: 0x24e72940  addiu       $a3, $a3, 0x2940
    ctx->pc = 0x1d5430u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10560));
    // 0x1d5434: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d5434u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d5438: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d5438u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d543c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d543cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d5440: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d5440u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5444: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d5444u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5448: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d5448u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d544c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D544Cu;
    SET_GPR_U32(ctx, 31, 0x1D5454u);
    ctx->pc = 0x1D5450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D544Cu;
            // 0x1d5450: 0x240a0090  addiu       $t2, $zero, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5454u; }
        if (ctx->pc != 0x1D5454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5454u; }
        if (ctx->pc != 0x1D5454u) { return; }
    }
    ctx->pc = 0x1D5454u;
label_1d5454:
    // 0x1d5454: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D5454u;
    {
        const bool branch_taken_0x1d5454 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5454u;
            // 0x1d5458: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5454) {
            ctx->pc = 0x1D5470u;
            goto label_1d5470;
        }
    }
    ctx->pc = 0x1D545Cu;
    // 0x1d545c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d545cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5460: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D5460u;
    SET_GPR_U32(ctx, 31, 0x1D5468u);
    ctx->pc = 0x1D5464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5460u;
            // 0x1d5464: 0x24846e60  addiu       $a0, $a0, 0x6E60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5468u; }
        if (ctx->pc != 0x1D5468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5468u; }
        if (ctx->pc != 0x1D5468u) { return; }
    }
    ctx->pc = 0x1D5468u;
label_1d5468:
    // 0x1d5468: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D5468u;
    {
        const bool branch_taken_0x1d5468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D546Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5468u;
            // 0x1d546c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5468) {
            ctx->pc = 0x1D5488u;
            goto label_1d5488;
        }
    }
    ctx->pc = 0x1D5470u;
label_1d5470:
    // 0x1d5470: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5470u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5474: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d5474u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5478: 0x24632840  addiu       $v1, $v1, 0x2840
    ctx->pc = 0x1d5478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
    // 0x1d547c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d547cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5480: 0xac700098  sw          $s0, 0x98($v1)
    ctx->pc = 0x1d5480u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 16));
    // 0x1d5484: 0xac640090  sw          $a0, 0x90($v1)
    ctx->pc = 0x1d5484u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 144), GPR_U32(ctx, 4));
label_1d5488:
    // 0x1d5488: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d5488u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1d548c:
    // 0x1d548c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d548cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5490: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5490u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5490u;
            // 0x1d5494: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D541Cu: goto label_1d541c;
            case 0x1D5454u: goto label_1d5454;
            case 0x1D5468u: goto label_1d5468;
            case 0x1D5470u: goto label_1d5470;
            case 0x1D5488u: goto label_1d5488;
            case 0x1D548Cu: goto label_1d548c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5498u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
