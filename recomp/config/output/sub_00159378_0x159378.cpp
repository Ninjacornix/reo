#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159378
// Address: 0x159378 - 0x159440
void sub_00159378_0x159378(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159378_0x159378");
#endif

    switch (ctx->pc) {
        case 0x1593a4u: goto label_1593a4;
        default: break;
    }

    ctx->pc = 0x159378u;

    // 0x159378: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x159378u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15937c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15937cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159380: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x159380u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159384: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x159384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159388: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x159388u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15938c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15938cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x159390: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x159390u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159394: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x159394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x159398: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x159398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15939c: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15939Cu;
    SET_GPR_U32(ctx, 31, 0x1593A4u);
    ctx->pc = 0x1593A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15939Cu;
            // 0x1593a0: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1593A4u; }
        if (ctx->pc != 0x1593A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1593A4u; }
        if (ctx->pc != 0x1593A4u) { return; }
    }
    ctx->pc = 0x1593A4u;
label_1593a4:
    // 0x1593a4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1593a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1593a8: 0x3c060003  lui         $a2, 0x3
    ctx->pc = 0x1593a8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)3 << 16));
    // 0x1593ac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1593acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1593b0: 0x34a5020f  ori         $a1, $a1, 0x20F
    ctx->pc = 0x1593b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)527);
    // 0x1593b4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1593B4u;
    {
        const bool branch_taken_0x1593b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1593B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1593B4u;
            // 0x1593b8: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1593b4) {
            ctx->pc = 0x1593D8u;
            goto label_1593d8;
        }
    }
    ctx->pc = 0x1593BCu;
    // 0x1593bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1593bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1593c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1593c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1593c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1593c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1593c8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1593c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1593cc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1593ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1593d0: 0x80563ce  j           func_158F38
    ctx->pc = 0x1593D0u;
    ctx->pc = 0x1593D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1593D0u;
            // 0x1593d4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1593D8u;
label_1593d8:
    // 0x1593d8: 0x8e020280  lw          $v0, 0x280($s0)
    ctx->pc = 0x1593d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 640)));
    // 0x1593dc: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1593dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1593e0: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1593e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1593e4: 0x8e030290  lw          $v1, 0x290($s0)
    ctx->pc = 0x1593e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 656)));
    // 0x1593e8: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1593e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1593ec: 0x8e04027c  lw          $a0, 0x27C($s0)
    ctx->pc = 0x1593ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 636)));
    // 0x1593f0: 0x54860003  bnel        $a0, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1593F0u;
    {
        const bool branch_taken_0x1593f0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        if (branch_taken_0x1593f0) {
            ctx->pc = 0x1593F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1593F0u;
            // 0x1593f4: 0x8e020290  lw          $v0, 0x290($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 656)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x159400u;
            goto label_159400;
        }
    }
    ctx->pc = 0x1593F8u;
    // 0x1593f8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1593F8u;
    {
        const bool branch_taken_0x1593f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1593FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1593F8u;
            // 0x1593fc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1593f8) {
            ctx->pc = 0x159418u;
            goto label_159418;
        }
    }
    ctx->pc = 0x159400u;
label_159400:
    // 0x159400: 0x24030708  addiu       $v1, $zero, 0x708
    ctx->pc = 0x159400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x159404: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x159404u;
    {
        const bool branch_taken_0x159404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x159404) {
            ctx->pc = 0x159408u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x159404u;
            // 0x159408: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x15940Cu;
            goto label_15940c;
        }
    }
    ctx->pc = 0x15940Cu;
label_15940c:
    // 0x15940c: 0x441018  mult        $v0, $v0, $a0
    ctx->pc = 0x15940cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x159410: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x159410u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x159414: 0x1012  mflo        $v0
    ctx->pc = 0x159414u;
    SET_GPR_U64(ctx, 2, ctx->lo);
label_159418:
    // 0x159418: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x159418u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x15941c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15941cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159420: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x159420u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159424: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159424u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x159428: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x159428u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15942c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15942cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159430: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x159430u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159434: 0x3e00008  jr          $ra
    ctx->pc = 0x159434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x159438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159434u;
            // 0x159438: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1593A4u: goto label_1593a4;
            case 0x1593D8u: goto label_1593d8;
            case 0x159400u: goto label_159400;
            case 0x15940Cu: goto label_15940c;
            case 0x159418u: goto label_159418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15943Cu;
    // 0x15943c: 0x0  nop
    ctx->pc = 0x15943cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
