#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F58
// Address: 0x124f58 - 0x1250a0
void sub_00124F58_0x124f58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F58_0x124f58");
#endif

    switch (ctx->pc) {
        case 0x124f90u: goto label_124f90;
        case 0x124fd0u: goto label_124fd0;
        case 0x125010u: goto label_125010;
        case 0x125028u: goto label_125028;
        case 0x12506cu: goto label_12506c;
        default: break;
    }

    ctx->pc = 0x124f58u;

    // 0x124f58: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x124f58u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x124f5c: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x124f5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x124f60: 0x3e00008  jr          $ra
    ctx->pc = 0x124F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F60u;
            // 0x124f64: 0x84a200de  lh          $v0, 0xDE($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 222)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F90u: goto label_124f90;
            case 0x124FD0u: goto label_124fd0;
            case 0x125010u: goto label_125010;
            case 0x125028u: goto label_125028;
            case 0x12506Cu: goto label_12506c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F68u;
    // 0x124f68: 0x3e00008  jr          $ra
    ctx->pc = 0x124F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F68u;
            // 0x124f6c: 0x248200cc  addiu       $v0, $a0, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 204));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F90u: goto label_124f90;
            case 0x124FD0u: goto label_124fd0;
            case 0x125010u: goto label_125010;
            case 0x125028u: goto label_125028;
            case 0x12506Cu: goto label_12506c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F70u;
    // 0x124f70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124f74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124f78: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124f78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124f7c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x124f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124f80: 0x260500a8  addiu       $a1, $s0, 0xA8
    ctx->pc = 0x124f80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 168));
    // 0x124f84: 0x260600ac  addiu       $a2, $s0, 0xAC
    ctx->pc = 0x124f84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 172));
    // 0x124f88: 0xc04d3c0  jal         func_134F00
    ctx->pc = 0x124F88u;
    SET_GPR_U32(ctx, 31, 0x124F90u);
    ctx->pc = 0x124F8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124F88u;
            // 0x124f8c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F00u;
    if (runtime->hasFunction(0x134F00u)) {
        auto targetFn = runtime->lookupFunction(0x134F00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124F90u; }
        if (ctx->pc != 0x124F90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F00_0x134f00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124F90u; }
        if (ctx->pc != 0x124F90u) { return; }
    }
    ctx->pc = 0x124F90u;
label_124f90:
    // 0x124f90: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124f90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124f94: 0x260700a6  addiu       $a3, $s0, 0xA6
    ctx->pc = 0x124f94u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 166));
    // 0x124f98: 0x260500a2  addiu       $a1, $s0, 0xA2
    ctx->pc = 0x124f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 162));
    // 0x124f9c: 0x260600a4  addiu       $a2, $s0, 0xA4
    ctx->pc = 0x124f9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 164));
    // 0x124fa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fa4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x124fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fa8: 0x804d3ce  j           func_134F38
    ctx->pc = 0x124FA8u;
    ctx->pc = 0x124FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FA8u;
            // 0x124fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F38u;
    if (runtime->hasFunction(0x134F38u)) {
        auto targetFn = runtime->lookupFunction(0x134F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00134F38_0x134f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124FB0u;
    // 0x124fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124fb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124fb8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124fb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124fbc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x124fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124fc0: 0x260500a8  addiu       $a1, $s0, 0xA8
    ctx->pc = 0x124fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 168));
    // 0x124fc4: 0x260600ac  addiu       $a2, $s0, 0xAC
    ctx->pc = 0x124fc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 172));
    // 0x124fc8: 0xc04d3b6  jal         func_134ED8
    ctx->pc = 0x124FC8u;
    SET_GPR_U32(ctx, 31, 0x124FD0u);
    ctx->pc = 0x124FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FC8u;
            // 0x124fcc: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134ED8u;
    if (runtime->hasFunction(0x134ED8u)) {
        auto targetFn = runtime->lookupFunction(0x134ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124FD0u; }
        if (ctx->pc != 0x124FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134ED8_0x134ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124FD0u; }
        if (ctx->pc != 0x124FD0u) { return; }
    }
    ctx->pc = 0x124FD0u;
label_124fd0:
    // 0x124fd0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124fd4: 0x860700a6  lh          $a3, 0xA6($s0)
    ctx->pc = 0x124fd4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 166)));
    // 0x124fd8: 0x860500a2  lh          $a1, 0xA2($s0)
    ctx->pc = 0x124fd8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 162)));
    // 0x124fdc: 0x860600a4  lh          $a2, 0xA4($s0)
    ctx->pc = 0x124fdcu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 164)));
    // 0x124fe0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x124fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fe4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124fe4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fe8: 0x804d3ca  j           func_134F28
    ctx->pc = 0x124FE8u;
    ctx->pc = 0x124FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124FE8u;
            // 0x124fec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F28u;
    if (runtime->hasFunction(0x134F28u)) {
        auto targetFn = runtime->lookupFunction(0x134F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00134F28_0x134f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124FF0u;
    // 0x124ff0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x124ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x124ff4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x124ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x124ff8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x124ff8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124ffc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x124ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x125000: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x125000u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125004: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x125004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x125008: 0xc042c56  jal         func_10B158
    ctx->pc = 0x125008u;
    SET_GPR_U32(ctx, 31, 0x125010u);
    ctx->pc = 0x12500Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125008u;
            // 0x12500c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125010u; }
        if (ctx->pc != 0x125010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125010u; }
        if (ctx->pc != 0x125010u) { return; }
    }
    ctx->pc = 0x125010u;
label_125010:
    // 0x125010: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125014: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x125014u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125018: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x125018u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12501c: 0x27a70002  addiu       $a3, $sp, 0x2
    ctx->pc = 0x12501cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x125020: 0xc049156  jal         func_124558
    ctx->pc = 0x125020u;
    SET_GPR_U32(ctx, 31, 0x125028u);
    ctx->pc = 0x125024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125020u;
            // 0x125024: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125028u; }
        if (ctx->pc != 0x125028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124558_0x124558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125028u; }
        if (ctx->pc != 0x125028u) { return; }
    }
    ctx->pc = 0x125028u;
label_125028:
    // 0x125028: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x125028u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12502c: 0x97a40002  lhu         $a0, 0x2($sp)
    ctx->pc = 0x12502cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x125030: 0x97a20004  lhu         $v0, 0x4($sp)
    ctx->pc = 0x125030u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x125034: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125038: 0xa623009c  sh          $v1, 0x9C($s1)
    ctx->pc = 0x125038u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 156), (uint16_t)GPR_U32(ctx, 3));
    // 0x12503c: 0xa62200a0  sh          $v0, 0xA0($s1)
    ctx->pc = 0x12503cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 160), (uint16_t)GPR_U32(ctx, 2));
    // 0x125040: 0xa624009e  sh          $a0, 0x9E($s1)
    ctx->pc = 0x125040u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 158), (uint16_t)GPR_U32(ctx, 4));
    // 0x125044: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x125044u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125048: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x125048u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12504c: 0x3e00008  jr          $ra
    ctx->pc = 0x12504Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12504Cu;
            // 0x125050: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F90u: goto label_124f90;
            case 0x124FD0u: goto label_124fd0;
            case 0x125010u: goto label_125010;
            case 0x125028u: goto label_125028;
            case 0x12506Cu: goto label_12506c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125054u;
    // 0x125054: 0x0  nop
    ctx->pc = 0x125054u;
    // NOP
    // 0x125058: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12505c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12505cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125060: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x125060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x125064: 0xc042c56  jal         func_10B158
    ctx->pc = 0x125064u;
    SET_GPR_U32(ctx, 31, 0x12506Cu);
    ctx->pc = 0x125068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125064u;
            // 0x125068: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12506Cu; }
        if (ctx->pc != 0x12506Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12506Cu; }
        if (ctx->pc != 0x12506Cu) { return; }
    }
    ctx->pc = 0x12506Cu;
label_12506c:
    // 0x12506c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12506cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125070: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125074: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x125074u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x125078: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x125078u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x12507c: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x12507cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x125080: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125084: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x125084u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125088: 0x24c6b94c  addiu       $a2, $a2, -0x46B4
    ctx->pc = 0x125088u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294949196));
    // 0x12508c: 0x24e7b94e  addiu       $a3, $a3, -0x46B2
    ctx->pc = 0x12508cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294949198));
    // 0x125090: 0x2508b950  addiu       $t0, $t0, -0x46B0
    ctx->pc = 0x125090u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294949200));
    // 0x125094: 0x8049156  j           func_124558
    ctx->pc = 0x125094u;
    ctx->pc = 0x125098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125094u;
            // 0x125098: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124558_0x124558(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12509Cu;
    // 0x12509c: 0x0  nop
    ctx->pc = 0x12509cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
