#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5600
// Address: 0x1f5600 - 0x1f5900
void sub_001F5600_0x1f5600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5600_0x1f5600");
#endif

    switch (ctx->pc) {
        case 0x1f562cu: goto label_1f562c;
        case 0x1f563cu: goto label_1f563c;
        case 0x1f564cu: goto label_1f564c;
        case 0x1f5658u: goto label_1f5658;
        case 0x1f5694u: goto label_1f5694;
        case 0x1f569cu: goto label_1f569c;
        case 0x1f56f8u: goto label_1f56f8;
        case 0x1f5740u: goto label_1f5740;
        case 0x1f58b0u: goto label_1f58b0;
        default: break;
    }

    ctx->pc = 0x1f5600u;

    // 0x1f5600: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f5600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f5604: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5604u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5608: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f560c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f560cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5610: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5614: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1F5614u;
    {
        const bool branch_taken_0x1f5614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5614u;
            // 0x1f5618: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5614) {
            ctx->pc = 0x1F56B8u;
            goto label_1f56b8;
        }
    }
    ctx->pc = 0x1F561Cu;
    // 0x1f561c: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x1f561cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1f5620: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f5620u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f5624: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F5624u;
    SET_GPR_U32(ctx, 31, 0x1F562Cu);
    ctx->pc = 0x1F5628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5624u;
            // 0x1f5628: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F562Cu; }
        if (ctx->pc != 0x1F562Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F562Cu; }
        if (ctx->pc != 0x1F562Cu) { return; }
    }
    ctx->pc = 0x1F562Cu;
label_1f562c:
    // 0x1f562c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f562cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5630: 0x9025ebd4  lbu         $a1, -0x142C($at)
    ctx->pc = 0x1f5630u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f5634: 0xc07d2e4  jal         func_1F4B90
    ctx->pc = 0x1F5634u;
    SET_GPR_U32(ctx, 31, 0x1F563Cu);
    ctx->pc = 0x1F5638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5634u;
            // 0x1f5638: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B90u;
    if (runtime->hasFunction(0x1F4B90u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F563Cu; }
        if (ctx->pc != 0x1F563Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B90_0x1f4b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F563Cu; }
        if (ctx->pc != 0x1F563Cu) { return; }
    }
    ctx->pc = 0x1F563Cu;
label_1f563c:
    // 0x1f563c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f563cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5640: 0x8c25ebd8  lw          $a1, -0x1428($at)
    ctx->pc = 0x1f5640u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962136)));
    // 0x1f5644: 0xc07d308  jal         func_1F4C20
    ctx->pc = 0x1F5644u;
    SET_GPR_U32(ctx, 31, 0x1F564Cu);
    ctx->pc = 0x1F5648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5644u;
            // 0x1f5648: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4C20u;
    if (runtime->hasFunction(0x1F4C20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F564Cu; }
        if (ctx->pc != 0x1F564Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4C20_0x1f4c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F564Cu; }
        if (ctx->pc != 0x1F564Cu) { return; }
    }
    ctx->pc = 0x1F564Cu;
label_1f564c:
    // 0x1f564c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f564cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5650: 0xc07d2e4  jal         func_1F4B90
    ctx->pc = 0x1F5650u;
    SET_GPR_U32(ctx, 31, 0x1F5658u);
    ctx->pc = 0x1F5654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5650u;
            // 0x1f5654: 0x240502f2  addiu       $a1, $zero, 0x2F2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 754));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B90u;
    if (runtime->hasFunction(0x1F4B90u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5658u; }
        if (ctx->pc != 0x1F5658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B90_0x1f4b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5658u; }
        if (ctx->pc != 0x1F5658u) { return; }
    }
    ctx->pc = 0x1F5658u;
label_1f5658:
    // 0x1f5658: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f5658u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f565c: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f565cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f5660: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f5660u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f5664: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f5664u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f5668: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f5668u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f566c: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f566cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f5670: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f5670u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f5674: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f5674u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f5678: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f5678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f567c: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f567cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f5680: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f5680u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f5684: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f5684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f5688: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f5688u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f568c: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F568Cu;
    SET_GPR_U32(ctx, 31, 0x1F5694u);
    ctx->pc = 0x1F5690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F568Cu;
            // 0x1f5690: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5694u; }
        if (ctx->pc != 0x1F5694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5694u; }
        if (ctx->pc != 0x1F5694u) { return; }
    }
    ctx->pc = 0x1F5694u;
label_1f5694:
    // 0x1f5694: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F5694u;
    SET_GPR_U32(ctx, 31, 0x1F569Cu);
    ctx->pc = 0x1F5698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5694u;
            // 0x1f5698: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F569Cu; }
        if (ctx->pc != 0x1F569Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F569Cu; }
        if (ctx->pc != 0x1F569Cu) { return; }
    }
    ctx->pc = 0x1F569Cu;
label_1f569c:
    // 0x1f569c: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f569cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f56a0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F56A0u;
    {
        const bool branch_taken_0x1f56a0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f56a0) {
            ctx->pc = 0x1F56B0u;
            goto label_1f56b0;
        }
    }
    ctx->pc = 0x1F56A8u;
    // 0x1f56a8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F56A8u;
    {
        const bool branch_taken_0x1f56a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F56ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F56A8u;
            // 0x1f56ac: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f56a8) {
            ctx->pc = 0x1F56C0u;
            goto label_1f56c0;
        }
    }
    ctx->pc = 0x1F56B0u;
label_1f56b0:
    // 0x1f56b0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f56b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f56b4: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f56b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f56b8:
    // 0x1f56b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f56b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f56bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f56bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f56c0:
    // 0x1f56c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f56c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f56c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F56C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F56C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F56C4u;
            // 0x1f56c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F562Cu: goto label_1f562c;
            case 0x1F563Cu: goto label_1f563c;
            case 0x1F564Cu: goto label_1f564c;
            case 0x1F5658u: goto label_1f5658;
            case 0x1F5694u: goto label_1f5694;
            case 0x1F569Cu: goto label_1f569c;
            case 0x1F56B0u: goto label_1f56b0;
            case 0x1F56B8u: goto label_1f56b8;
            case 0x1F56C0u: goto label_1f56c0;
            case 0x1F56F8u: goto label_1f56f8;
            case 0x1F5738u: goto label_1f5738;
            case 0x1F5740u: goto label_1f5740;
            case 0x1F5780u: goto label_1f5780;
            case 0x1F57F4u: goto label_1f57f4;
            case 0x1F5810u: goto label_1f5810;
            case 0x1F5868u: goto label_1f5868;
            case 0x1F5884u: goto label_1f5884;
            case 0x1F5888u: goto label_1f5888;
            case 0x1F58B0u: goto label_1f58b0;
            case 0x1F58E0u: goto label_1f58e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F56CCu;
    // 0x1f56cc: 0x0  nop
    ctx->pc = 0x1f56ccu;
    // NOP
    // 0x1f56d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f56d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f56d4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f56d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f56d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f56d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f56dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f56dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f56e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f56e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f56e4: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f56e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f56e8: 0x1040007d  beqz        $v0, . + 4 + (0x7D << 2)
    ctx->pc = 0x1F56E8u;
    {
        const bool branch_taken_0x1f56e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F56ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F56E8u;
            // 0x1f56ec: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f56e8) {
            ctx->pc = 0x1F58E0u;
            goto label_1f58e0;
        }
    }
    ctx->pc = 0x1F56F0u;
    // 0x1f56f0: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F56F0u;
    SET_GPR_U32(ctx, 31, 0x1F56F8u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F56F8u; }
        if (ctx->pc != 0x1F56F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F56F8u; }
        if (ctx->pc != 0x1F56F8u) { return; }
    }
    ctx->pc = 0x1F56F8u;
label_1f56f8:
    // 0x1f56f8: 0x3050ffff  andi        $s0, $v0, 0xFFFF
    ctx->pc = 0x1f56f8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f56fc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f56fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5700: 0x9022ebd4  lbu         $v0, -0x142C($at)
    ctx->pc = 0x1f5700u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f5704: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1F5704u;
    {
        const bool branch_taken_0x1f5704 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F5708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5704u;
            // 0x1f5708: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5704) {
            ctx->pc = 0x1F5738u;
            goto label_1f5738;
        }
    }
    ctx->pc = 0x1F570Cu;
    // 0x1f570c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f570cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5710: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f5710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5714: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f5714u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f5718: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f5718u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f571c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f571cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5720: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5720u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5724: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5724u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5728: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f5728u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f572c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f572cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5730: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5730u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5734: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5734u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f5738:
    // 0x1f5738: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5738u;
    SET_GPR_U32(ctx, 31, 0x1F5740u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5740u; }
        if (ctx->pc != 0x1F5740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5740u; }
        if (ctx->pc != 0x1F5740u) { return; }
    }
    ctx->pc = 0x1F5740u;
label_1f5740:
    // 0x1f5740: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5740u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5744: 0x8c23ebd8  lw          $v1, -0x1428($at)
    ctx->pc = 0x1f5744u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962136)));
    // 0x1f5748: 0x1043000d  beq         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1F5748u;
    {
        const bool branch_taken_0x1f5748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F574Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5748u;
            // 0x1f574c: 0x3203ffff  andi        $v1, $s0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5748) {
            ctx->pc = 0x1F5780u;
            goto label_1f5780;
        }
    }
    ctx->pc = 0x1F5750u;
    // 0x1f5750: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1f5750u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5754: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f5754u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5758: 0xae24008c  sw          $a0, 0x8C($s1)
    ctx->pc = 0x1f5758u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 4));
    // 0x1f575c: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f575cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f5760: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f5760u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5764: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5764u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5768: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5768u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f576c: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f576cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5770: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f5770u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5774: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5774u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5778: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5778u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f577c: 0x3203ffff  andi        $v1, $s0, 0xFFFF
    ctx->pc = 0x1f577cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
label_1f5780:
    // 0x1f5780: 0x3c050036  lui         $a1, 0x36
    ctx->pc = 0x1f5780u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
    // 0x1f5784: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1f5784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f5788: 0x33080  sll         $a2, $v1, 2
    ctx->pc = 0x1f5788u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f578c: 0x24a5ebb4  addiu       $a1, $a1, -0x144C
    ctx->pc = 0x1f578cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962100));
    // 0x1f5790: 0xa2240001  sb          $a0, 0x1($s1)
    ctx->pc = 0x1f5790u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1f5794: 0xa63821  addu        $a3, $a1, $a2
    ctx->pc = 0x1f5794u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1f5798: 0x244802f2  addiu       $t0, $v0, 0x2F2
    ctx->pc = 0x1f5798u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 754));
    // 0x1f579c: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1f579cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1f57a0: 0x106282b  sltu        $a1, $t0, $a2
    ctx->pc = 0x1f57a0u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1f57a4: 0x14a0001a  bnez        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1F57A4u;
    {
        const bool branch_taken_0x1f57a4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F57A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F57A4u;
            // 0x1f57a8: 0x640402f2  daddiu      $a0, $zero, 0x2F2 (Delay Slot)
        SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)754);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f57a4) {
            ctx->pc = 0x1F5810u;
            goto label_1f5810;
        }
    }
    ctx->pc = 0x1F57ACu;
    // 0x1f57ac: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57b0: 0xc22023  subu        $a0, $a2, $v0
    ctx->pc = 0x1f57b0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1f57b4: 0xac20ebd8  sw          $zero, -0x1428($at)
    ctx->pc = 0x1f57b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
    // 0x1f57b8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57bc: 0x9026ebd4  lbu         $a2, -0x142C($at)
    ctx->pc = 0x1f57bcu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f57c0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57c4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f57c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f57c8: 0x9425ebb0  lhu         $a1, -0x1450($at)
    ctx->pc = 0x1f57c8u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962096)));
    // 0x1f57cc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57d0: 0xa026ebd4  sb          $a2, -0x142C($at)
    ctx->pc = 0x1f57d0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 6));
    // 0x1f57d4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57d8: 0x9026ebd4  lbu         $a2, -0x142C($at)
    ctx->pc = 0x1f57d8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f57dc: 0xc5082a  slt         $at, $a2, $a1
    ctx->pc = 0x1f57dcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1f57e0: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F57E0u;
    {
        const bool branch_taken_0x1f57e0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F57E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F57E0u;
            // 0x1f57e4: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f57e0) {
            ctx->pc = 0x1F57F4u;
            goto label_1f57f4;
        }
    }
    ctx->pc = 0x1F57E8u;
    // 0x1f57e8: 0x28c50008  slti        $a1, $a2, 0x8
    ctx->pc = 0x1f57e8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1f57ec: 0x14a00026  bnez        $a1, . + 4 + (0x26 << 2)
    ctx->pc = 0x1F57ECu;
    {
        const bool branch_taken_0x1f57ec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f57ec) {
            ctx->pc = 0x1F5888u;
            goto label_1f5888;
        }
    }
    ctx->pc = 0x1F57F4u;
label_1f57f4:
    // 0x1f57f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f57f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f57f8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1f57f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f57fc: 0xa020ebd4  sb          $zero, -0x142C($at)
    ctx->pc = 0x1f57fcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5800: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5800u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5804: 0xac20ebd8  sw          $zero, -0x1428($at)
    ctx->pc = 0x1f5804u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
    // 0x1f5808: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1F5808u;
    {
        const bool branch_taken_0x1f5808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F580Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5808u;
            // 0x1f580c: 0xa2250001  sb          $a1, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5808) {
            ctx->pc = 0x1F5888u;
            goto label_1f5888;
        }
    }
    ctx->pc = 0x1F5810u;
label_1f5810:
    // 0x1f5810: 0x2d050400  sltiu       $a1, $t0, 0x400
    ctx->pc = 0x1f5810u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)1024) ? 1 : 0);
    // 0x1f5814: 0x14a0001b  bnez        $a1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1F5814u;
    {
        const bool branch_taken_0x1f5814 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5814u;
            // 0x1f5818: 0x3c010036  lui         $at, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5814) {
            ctx->pc = 0x1F5884u;
            goto label_1f5884;
        }
    }
    ctx->pc = 0x1F581Cu;
    // 0x1f581c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f581cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5820: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1f5820u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1f5824: 0xac20ebd8  sw          $zero, -0x1428($at)
    ctx->pc = 0x1f5824u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
    // 0x1f5828: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x1f5828u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f582c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f582cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5830: 0x9026ebd4  lbu         $a2, -0x142C($at)
    ctx->pc = 0x1f5830u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f5834: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5834u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5838: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f5838u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f583c: 0x9425ebb0  lhu         $a1, -0x1450($at)
    ctx->pc = 0x1f583cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962096)));
    // 0x1f5840: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5840u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5844: 0xa026ebd4  sb          $a2, -0x142C($at)
    ctx->pc = 0x1f5844u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 6));
    // 0x1f5848: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f584c: 0x9026ebd4  lbu         $a2, -0x142C($at)
    ctx->pc = 0x1f584cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962132)));
    // 0x1f5850: 0xc5082a  slt         $at, $a2, $a1
    ctx->pc = 0x1f5850u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1f5854: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5854u;
    {
        const bool branch_taken_0x1f5854 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5854u;
            // 0x1f5858: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5854) {
            ctx->pc = 0x1F5868u;
            goto label_1f5868;
        }
    }
    ctx->pc = 0x1F585Cu;
    // 0x1f585c: 0x28c50008  slti        $a1, $a2, 0x8
    ctx->pc = 0x1f585cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1f5860: 0x14a00009  bnez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1F5860u;
    {
        const bool branch_taken_0x1f5860 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f5860) {
            ctx->pc = 0x1F5888u;
            goto label_1f5888;
        }
    }
    ctx->pc = 0x1F5868u;
label_1f5868:
    // 0x1f5868: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5868u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f586c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1f586cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f5870: 0xa020ebd4  sb          $zero, -0x142C($at)
    ctx->pc = 0x1f5870u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5874: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5874u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5878: 0xac20ebd8  sw          $zero, -0x1428($at)
    ctx->pc = 0x1f5878u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
    // 0x1f587c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F587Cu;
    {
        const bool branch_taken_0x1f587c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F587Cu;
            // 0x1f5880: 0xa2250001  sb          $a1, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f587c) {
            ctx->pc = 0x1F5888u;
            goto label_1f5888;
        }
    }
    ctx->pc = 0x1F5884u;
label_1f5884:
    // 0x1f5884: 0xac28ebd8  sw          $t0, -0x1428($at)
    ctx->pc = 0x1f5884u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 8));
label_1f5888:
    // 0x1f5888: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x1f5888u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1f588c: 0x10a00014  beqz        $a1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F588Cu;
    {
        const bool branch_taken_0x1f588c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F588Cu;
            // 0x1f5890: 0x32a80  sll         $a1, $v1, 10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f588c) {
            ctx->pc = 0x1F58E0u;
            goto label_1f58e0;
        }
    }
    ctx->pc = 0x1F5894u;
    // 0x1f5894: 0x3086ffff  andi        $a2, $a0, 0xFFFF
    ctx->pc = 0x1f5894u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1f5898: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1f5898u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1f589c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f589cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f58a0: 0x24635ad0  addiu       $v1, $v1, 0x5AD0
    ctx->pc = 0x1f58a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23248));
    // 0x1f58a4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1f58a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1f58a8: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F58A8u;
    SET_GPR_U32(ctx, 31, 0x1F58B0u);
    ctx->pc = 0x1F58ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F58A8u;
            // 0x1f58ac: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F58B0u; }
        if (ctx->pc != 0x1F58B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F58B0u; }
        if (ctx->pc != 0x1F58B0u) { return; }
    }
    ctx->pc = 0x1F58B0u;
label_1f58b0:
    // 0x1f58b0: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F58B0u;
    {
        const bool branch_taken_0x1f58b0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F58B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F58B0u;
            // 0x1f58b4: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f58b0) {
            ctx->pc = 0x1F58E0u;
            goto label_1f58e0;
        }
    }
    ctx->pc = 0x1F58B8u;
    // 0x1f58b8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f58b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f58bc: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f58bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f58c0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f58c0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f58c4: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f58c4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f58c8: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f58c8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f58cc: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f58ccu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f58d0: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f58d0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f58d4: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f58d4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f58d8: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f58d8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f58dc: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f58dcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f58e0:
    // 0x1f58e0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f58e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f58e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f58e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f58e8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f58e8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f58ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f58ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f58f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F58F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F58F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F58F0u;
            // 0x1f58f4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F562Cu: goto label_1f562c;
            case 0x1F563Cu: goto label_1f563c;
            case 0x1F564Cu: goto label_1f564c;
            case 0x1F5658u: goto label_1f5658;
            case 0x1F5694u: goto label_1f5694;
            case 0x1F569Cu: goto label_1f569c;
            case 0x1F56B0u: goto label_1f56b0;
            case 0x1F56B8u: goto label_1f56b8;
            case 0x1F56C0u: goto label_1f56c0;
            case 0x1F56F8u: goto label_1f56f8;
            case 0x1F5738u: goto label_1f5738;
            case 0x1F5740u: goto label_1f5740;
            case 0x1F5780u: goto label_1f5780;
            case 0x1F57F4u: goto label_1f57f4;
            case 0x1F5810u: goto label_1f5810;
            case 0x1F5868u: goto label_1f5868;
            case 0x1F5884u: goto label_1f5884;
            case 0x1F5888u: goto label_1f5888;
            case 0x1F58B0u: goto label_1f58b0;
            case 0x1F58E0u: goto label_1f58e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F58F8u;
    // 0x1f58f8: 0x0  nop
    ctx->pc = 0x1f58f8u;
    // NOP
    // 0x1f58fc: 0x0  nop
    ctx->pc = 0x1f58fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
