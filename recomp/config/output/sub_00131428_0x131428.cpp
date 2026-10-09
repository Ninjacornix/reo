#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131428
// Address: 0x131428 - 0x1315e0
void sub_00131428_0x131428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131428_0x131428");
#endif

    switch (ctx->pc) {
        case 0x13144cu: goto label_13144c;
        case 0x131468u: goto label_131468;
        case 0x1314acu: goto label_1314ac;
        case 0x1314c8u: goto label_1314c8;
        case 0x131510u: goto label_131510;
        case 0x131520u: goto label_131520;
        case 0x131538u: goto label_131538;
        case 0x131550u: goto label_131550;
        case 0x131560u: goto label_131560;
        case 0x131570u: goto label_131570;
        case 0x13158cu: goto label_13158c;
        case 0x1315a8u: goto label_1315a8;
        default: break;
    }

    ctx->pc = 0x131428u;

    // 0x131428: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13142c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x13142cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131430: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x131430u;
    {
        const bool branch_taken_0x131430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131430u;
            // 0x131434: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131430) {
            ctx->pc = 0x131458u;
            goto label_131458;
        }
    }
    ctx->pc = 0x131438u;
    // 0x131438: 0x8c470004  lw          $a3, 0x4($v0)
    ctx->pc = 0x131438u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x13143c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x13143cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x131440: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x131440u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x131444: 0xc04f20e  jal         func_13C838
    ctx->pc = 0x131444u;
    SET_GPR_U32(ctx, 31, 0x13144Cu);
    ctx->pc = 0x131448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131444u;
            // 0x131448: 0x8c46000c  lw          $a2, 0xC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C838u;
    if (runtime->hasFunction(0x13C838u)) {
        auto targetFn = runtime->lookupFunction(0x13C838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13144Cu; }
        if (ctx->pc != 0x13144Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C838_0x13c838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13144Cu; }
        if (ctx->pc != 0x13144Cu) { return; }
    }
    ctx->pc = 0x13144Cu;
label_13144c:
    // 0x13144c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13144Cu;
    {
        const bool branch_taken_0x13144c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13144Cu;
            // 0x131450: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13144c) {
            ctx->pc = 0x13146Cu;
            goto label_13146c;
        }
    }
    ctx->pc = 0x131454u;
    // 0x131454: 0x0  nop
    ctx->pc = 0x131454u;
    // NOP
label_131458:
    // 0x131458: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13145c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13145cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131460: 0xc04f20e  jal         func_13C838
    ctx->pc = 0x131460u;
    SET_GPR_U32(ctx, 31, 0x131468u);
    ctx->pc = 0x131464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131460u;
            // 0x131464: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C838u;
    if (runtime->hasFunction(0x13C838u)) {
        auto targetFn = runtime->lookupFunction(0x13C838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131468u; }
        if (ctx->pc != 0x131468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C838_0x13c838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131468u; }
        if (ctx->pc != 0x131468u) { return; }
    }
    ctx->pc = 0x131468u;
label_131468:
    // 0x131468: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13146c:
    // 0x13146c: 0x3e00008  jr          $ra
    ctx->pc = 0x13146Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13146Cu;
            // 0x131470: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13144Cu: goto label_13144c;
            case 0x131458u: goto label_131458;
            case 0x131468u: goto label_131468;
            case 0x13146Cu: goto label_13146c;
            case 0x1314ACu: goto label_1314ac;
            case 0x1314C0u: goto label_1314c0;
            case 0x1314C8u: goto label_1314c8;
            case 0x131510u: goto label_131510;
            case 0x131520u: goto label_131520;
            case 0x131538u: goto label_131538;
            case 0x131550u: goto label_131550;
            case 0x131560u: goto label_131560;
            case 0x131570u: goto label_131570;
            case 0x13158Cu: goto label_13158c;
            case 0x1315A8u: goto label_1315a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131474u;
    // 0x131474: 0x0  nop
    ctx->pc = 0x131474u;
    // NOP
    // 0x131478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13147c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13147cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131480: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131484: 0x804f270  j           func_13C9C0
    ctx->pc = 0x131484u;
    ctx->pc = 0x131488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131484u;
            // 0x131488: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C9C0u;
    if (runtime->hasFunction(0x13C9C0u)) {
        auto targetFn = runtime->lookupFunction(0x13C9C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013C9C0_0x13c9c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13148Cu;
    // 0x13148c: 0x0  nop
    ctx->pc = 0x13148cu;
    // NOP
    // 0x131490: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131494: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131498: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131498u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13149c: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13149Cu;
    {
        const bool branch_taken_0x13149c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1314A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13149Cu;
            // 0x1314a0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13149c) {
            ctx->pc = 0x1314C0u;
            goto label_1314c0;
        }
    }
    ctx->pc = 0x1314A4u;
    // 0x1314a4: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x1314A4u;
    SET_GPR_U32(ctx, 31, 0x1314ACu);
    ctx->pc = 0x1314A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314A4u;
            // 0x1314a8: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314ACu; }
        if (ctx->pc != 0x1314ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314ACu; }
        if (ctx->pc != 0x1314ACu) { return; }
    }
    ctx->pc = 0x1314ACu;
label_1314ac:
    // 0x1314ac: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1314acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1314b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1314b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1314b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1314b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1314b8: 0x804f286  j           func_13CA18
    ctx->pc = 0x1314B8u;
    ctx->pc = 0x1314BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314B8u;
            // 0x1314bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CA18_0x13ca18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1314C0u;
label_1314c0:
    // 0x1314c0: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x1314C0u;
    SET_GPR_U32(ctx, 31, 0x1314C8u);
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314C8u; }
        if (ctx->pc != 0x1314C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314C8u; }
        if (ctx->pc != 0x1314C8u) { return; }
    }
    ctx->pc = 0x1314C8u;
label_1314c8:
    // 0x1314c8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1314c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1314cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1314ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1314d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1314d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1314d4: 0x804f286  j           func_13CA18
    ctx->pc = 0x1314D4u;
    ctx->pc = 0x1314D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314D4u;
            // 0x1314d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CA18_0x13ca18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1314DCu;
    // 0x1314dc: 0x0  nop
    ctx->pc = 0x1314dcu;
    // NOP
    // 0x1314e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1314e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1314e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1314e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1314e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1314e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1314ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1314ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1314f0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1314f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1314f4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1314f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1314f8: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1314f8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1314fc: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1314fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x131500: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131504: 0x8e90000c  lw          $s0, 0xC($s4)
    ctx->pc = 0x131504u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x131508: 0xc04fc78  jal         func_13F1E0
    ctx->pc = 0x131508u;
    SET_GPR_U32(ctx, 31, 0x131510u);
    ctx->pc = 0x13150Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131508u;
            // 0x13150c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F1E0u;
    if (runtime->hasFunction(0x13F1E0u)) {
        auto targetFn = runtime->lookupFunction(0x13F1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131510u; }
        if (ctx->pc != 0x131510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F1E0_0x13f1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131510u; }
        if (ctx->pc != 0x131510u) { return; }
    }
    ctx->pc = 0x131510u;
label_131510:
    // 0x131510: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x131510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131514: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131514u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131518: 0xc04fc72  jal         func_13F1C8
    ctx->pc = 0x131518u;
    SET_GPR_U32(ctx, 31, 0x131520u);
    ctx->pc = 0x13151Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131518u;
            // 0x13151c: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F1C8u;
    if (runtime->hasFunction(0x13F1C8u)) {
        auto targetFn = runtime->lookupFunction(0x13F1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131520u; }
        if (ctx->pc != 0x131520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F1C8_0x13f1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131520u; }
        if (ctx->pc != 0x131520u) { return; }
    }
    ctx->pc = 0x131520u;
label_131520:
    // 0x131520: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x131520u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131524: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x131524u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131528: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x131528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13152c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13152cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x131530: 0x40f809  jalr        $v0
    ctx->pc = 0x131530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131538u);
        ctx->pc = 0x131534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131530u;
            // 0x131534: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x131538u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13144Cu: goto label_13144c;
            case 0x131458u: goto label_131458;
            case 0x131468u: goto label_131468;
            case 0x13146Cu: goto label_13146c;
            case 0x1314ACu: goto label_1314ac;
            case 0x1314C0u: goto label_1314c0;
            case 0x1314C8u: goto label_1314c8;
            case 0x131510u: goto label_131510;
            case 0x131520u: goto label_131520;
            case 0x131538u: goto label_131538;
            case 0x131550u: goto label_131550;
            case 0x131560u: goto label_131560;
            case 0x131570u: goto label_131570;
            case 0x13158Cu: goto label_13158c;
            case 0x1315A8u: goto label_1315a8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131538u; }
            if (ctx->pc != 0x131538u) { return; }
        }
        }
    }
    ctx->pc = 0x131538u;
label_131538:
    // 0x131538: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x131538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13153c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x13153cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131540: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x131540u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131544: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x131544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x131548: 0x40f809  jalr        $v0
    ctx->pc = 0x131548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131550u);
        ctx->pc = 0x13154Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131548u;
            // 0x13154c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x131550u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13144Cu: goto label_13144c;
            case 0x131458u: goto label_131458;
            case 0x131468u: goto label_131468;
            case 0x13146Cu: goto label_13146c;
            case 0x1314ACu: goto label_1314ac;
            case 0x1314C0u: goto label_1314c0;
            case 0x1314C8u: goto label_1314c8;
            case 0x131510u: goto label_131510;
            case 0x131520u: goto label_131520;
            case 0x131538u: goto label_131538;
            case 0x131550u: goto label_131550;
            case 0x131560u: goto label_131560;
            case 0x131570u: goto label_131570;
            case 0x13158Cu: goto label_13158c;
            case 0x1315A8u: goto label_1315a8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131550u; }
            if (ctx->pc != 0x131550u) { return; }
        }
        }
    }
    ctx->pc = 0x131550u;
label_131550:
    // 0x131550: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x131550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131554: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x131554u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131558: 0xc050374  jal         func_140DD0
    ctx->pc = 0x131558u;
    SET_GPR_U32(ctx, 31, 0x131560u);
    ctx->pc = 0x13155Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131558u;
            // 0x13155c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131560u; }
        if (ctx->pc != 0x131560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131560u; }
        if (ctx->pc != 0x131560u) { return; }
    }
    ctx->pc = 0x131560u;
label_131560:
    // 0x131560: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x131560u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131564: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131564u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131568: 0xc050374  jal         func_140DD0
    ctx->pc = 0x131568u;
    SET_GPR_U32(ctx, 31, 0x131570u);
    ctx->pc = 0x13156Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131568u;
            // 0x13156c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131570u; }
        if (ctx->pc != 0x131570u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131570u; }
        if (ctx->pc != 0x131570u) { return; }
    }
    ctx->pc = 0x131570u;
label_131570:
    // 0x131570: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x131570u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x131574: 0x2533821  addu        $a3, $s2, $s3
    ctx->pc = 0x131574u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x131578: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x131578u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13157c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x13157cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131580: 0x2484ae50  addiu       $a0, $a0, -0x51B0
    ctx->pc = 0x131580u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946384));
    // 0x131584: 0xc045a12  jal         func_116848
    ctx->pc = 0x131584u;
    SET_GPR_U32(ctx, 31, 0x13158Cu);
    ctx->pc = 0x131588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131584u;
            // 0x131588: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13158Cu; }
        if (ctx->pc != 0x13158Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13158Cu; }
        if (ctx->pc != 0x13158Cu) { return; }
    }
    ctx->pc = 0x13158Cu;
label_13158c:
    // 0x13158c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13158cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x131590: 0x2113821  addu        $a3, $s0, $s1
    ctx->pc = 0x131590u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x131594: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x131594u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131598: 0x2138021  addu        $s0, $s0, $s3
    ctx->pc = 0x131598u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x13159c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x13159cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1315a0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1315A0u;
    SET_GPR_U32(ctx, 31, 0x1315A8u);
    ctx->pc = 0x1315A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1315A0u;
            // 0x1315a4: 0x2484ae70  addiu       $a0, $a0, -0x5190 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946416));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1315A8u; }
        if (ctx->pc != 0x1315A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1315A8u; }
        if (ctx->pc != 0x1315A8u) { return; }
    }
    ctx->pc = 0x1315A8u;
label_1315a8:
    // 0x1315a8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1315a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1315ac: 0x2519021  addu        $s2, $s2, $s1
    ctx->pc = 0x1315acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x1315b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1315b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1315b4: 0x2503021  addu        $a2, $s2, $s0
    ctx->pc = 0x1315b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1315b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1315b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1315bc: 0x82850001  lb          $a1, 0x1($s4)
    ctx->pc = 0x1315bcu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x1315c0: 0x2484ae90  addiu       $a0, $a0, -0x5170
    ctx->pc = 0x1315c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946448));
    // 0x1315c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1315c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1315c8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1315c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1315cc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1315ccu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1315d0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1315d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1315d4: 0x8045a12  j           func_116848
    ctx->pc = 0x1315D4u;
    ctx->pc = 0x1315D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1315D4u;
            // 0x1315d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1315DCu;
    // 0x1315dc: 0x0  nop
    ctx->pc = 0x1315dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
