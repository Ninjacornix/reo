#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001400C0
// Address: 0x1400c0 - 0x1401f8
void sub_001400C0_0x1400c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001400C0_0x1400c0");
#endif

    switch (ctx->pc) {
        case 0x1400f8u: goto label_1400f8;
        case 0x140190u: goto label_140190;
        case 0x1401c8u: goto label_1401c8;
        default: break;
    }

    ctx->pc = 0x1400c0u;

    // 0x1400c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1400c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1400c4: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1400c4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1400c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1400c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1400cc: 0x25038c98  addiu       $v1, $t0, -0x7368
    ctx->pc = 0x1400ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294937752));
    // 0x1400d0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1400d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1400d4: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x1400d4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1400d8: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1400d8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1400dc: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x1400dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1400e0: 0x80620004  lb          $v0, 0x4($v1)
    ctx->pc = 0x1400e0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1400e4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1400E4u;
    {
        const bool branch_taken_0x1400e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1400E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1400E4u;
            // 0x1400e8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1400e4) {
            ctx->pc = 0x14011Cu;
            goto label_14011c;
        }
    }
    ctx->pc = 0x1400ECu;
    // 0x1400ec: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1400ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1400f0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1400f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1400f4: 0x0  nop
    ctx->pc = 0x1400f4u;
    // NOP
label_1400f8:
    // 0x1400f8: 0x28820040  slti        $v0, $a0, 0x40
    ctx->pc = 0x1400f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1400fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1400FCu;
    {
        const bool branch_taken_0x1400fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x140100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1400FCu;
            // 0x140100: 0x24630030  addiu       $v1, $v1, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1400fc) {
            ctx->pc = 0x14011Cu;
            goto label_14011c;
        }
    }
    ctx->pc = 0x140104u;
    // 0x140104: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x140104u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140108: 0x0  nop
    ctx->pc = 0x140108u;
    // NOP
    // 0x14010c: 0x0  nop
    ctx->pc = 0x14010cu;
    // NOP
    // 0x140110: 0x0  nop
    ctx->pc = 0x140110u;
    // NOP
    // 0x140114: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x140114u;
    {
        const bool branch_taken_0x140114 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x140114) {
            ctx->pc = 0x140118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140114u;
            // 0x140118: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1400F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1400f8;
        }
    }
    ctx->pc = 0x14011Cu;
label_14011c:
    // 0x14011c: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x14011cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x140120: 0x1083001c  beq         $a0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x140120u;
    {
        const bool branch_taken_0x140120 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x140124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140120u;
            // 0x140124: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140120) {
            ctx->pc = 0x140194u;
            goto label_140194;
        }
    }
    ctx->pc = 0x140128u;
    // 0x140128: 0x48040  sll         $s0, $a0, 1
    ctx->pc = 0x140128u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x14012c: 0x25038c98  addiu       $v1, $t0, -0x7368
    ctx->pc = 0x14012cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294937752));
    // 0x140130: 0x2048021  addu        $s0, $s0, $a0
    ctx->pc = 0x140130u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x140134: 0x24e4000f  addiu       $a0, $a3, 0xF
    ctx->pc = 0x140134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 15));
    // 0x140138: 0x28e20000  slti        $v0, $a3, 0x0
    ctx->pc = 0x140138u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x14013c: 0x108100  sll         $s0, $s0, 4
    ctx->pc = 0x14013cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x140140: 0x2038021  addu        $s0, $s0, $v1
    ctx->pc = 0x140140u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x140144: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140144u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140148: 0x82380b  movn        $a3, $a0, $v0
    ctx->pc = 0x140148u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 4));
    // 0x14014c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14014cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140150: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x140150u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x140154: 0x3c060014  lui         $a2, 0x14
    ctx->pc = 0x140154u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)20 << 16));
    // 0x140158: 0x24638c60  addiu       $v1, $v1, -0x73A0
    ctx->pc = 0x140158u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937696));
    // 0x14015c: 0x24a5da78  addiu       $a1, $a1, -0x2588
    ctx->pc = 0x14015cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294957688));
    // 0x140160: 0x73903  sra         $a3, $a3, 4
    ctx->pc = 0x140160u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 4));
    // 0x140164: 0x24c60000  addiu       $a2, $a2, 0x0
    ctx->pc = 0x140164u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 0));
    // 0x140168: 0xa2020004  sb          $v0, 0x4($s0)
    ctx->pc = 0x140168u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x14016c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14016cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140170: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x140170u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x140174: 0xa2090005  sb          $t1, 0x5($s0)
    ctx->pc = 0x140174u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 9));
    // 0x140178: 0xae050008  sw          $a1, 0x8($s0)
    ctx->pc = 0x140178u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x14017c: 0xae0a000c  sw          $t2, 0xC($s0)
    ctx->pc = 0x14017cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 10));
    // 0x140180: 0xae070010  sw          $a3, 0x10($s0)
    ctx->pc = 0x140180u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 7));
    // 0x140184: 0xae060028  sw          $a2, 0x28($s0)
    ctx->pc = 0x140184u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 6));
    // 0x140188: 0xc05007e  jal         func_1401F8
    ctx->pc = 0x140188u;
    SET_GPR_U32(ctx, 31, 0x140190u);
    ctx->pc = 0x14018Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140188u;
            // 0x14018c: 0xae10002c  sw          $s0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1401F8u;
    if (runtime->hasFunction(0x1401F8u)) {
        auto targetFn = runtime->lookupFunction(0x1401F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140190u; }
        if (ctx->pc != 0x140190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001401F8_0x1401f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140190u; }
        if (ctx->pc != 0x140190u) { return; }
    }
    ctx->pc = 0x140190u;
label_140190:
    // 0x140190: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x140190u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_140194:
    // 0x140194: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140194u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140198: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14019c: 0x3e00008  jr          $ra
    ctx->pc = 0x14019Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14019Cu;
            // 0x1401a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1400F8u: goto label_1400f8;
            case 0x14011Cu: goto label_14011c;
            case 0x140190u: goto label_140190;
            case 0x140194u: goto label_140194;
            case 0x1401C8u: goto label_1401c8;
            case 0x1401CCu: goto label_1401cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1401A4u;
    // 0x1401a4: 0x0  nop
    ctx->pc = 0x1401a4u;
    // NOP
    // 0x1401a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1401a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1401ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1401acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1401b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1401b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1401b4: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1401B4u;
    {
        const bool branch_taken_0x1401b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1401B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401B4u;
            // 0x1401b8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1401b4) {
            ctx->pc = 0x1401CCu;
            goto label_1401cc;
        }
    }
    ctx->pc = 0x1401BCu;
    // 0x1401bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1401bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1401c0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1401C0u;
    SET_GPR_U32(ctx, 31, 0x1401C8u);
    ctx->pc = 0x1401C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1401C0u;
            // 0x1401c4: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1401C8u; }
        if (ctx->pc != 0x1401C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1401C8u; }
        if (ctx->pc != 0x1401C8u) { return; }
    }
    ctx->pc = 0x1401C8u;
label_1401c8:
    // 0x1401c8: 0xa2000004  sb          $zero, 0x4($s0)
    ctx->pc = 0x1401c8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 0));
label_1401cc:
    // 0x1401cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1401ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1401d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1401d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1401d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1401D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401D4u;
            // 0x1401d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1400F8u: goto label_1400f8;
            case 0x14011Cu: goto label_14011c;
            case 0x140190u: goto label_140190;
            case 0x140194u: goto label_140194;
            case 0x1401C8u: goto label_1401c8;
            case 0x1401CCu: goto label_1401cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1401DCu;
    // 0x1401dc: 0x0  nop
    ctx->pc = 0x1401dcu;
    // NOP
    // 0x1401e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1401E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401E0u;
            // 0x1401e4: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1400F8u: goto label_1400f8;
            case 0x14011Cu: goto label_14011c;
            case 0x140190u: goto label_140190;
            case 0x140194u: goto label_140194;
            case 0x1401C8u: goto label_1401c8;
            case 0x1401CCu: goto label_1401cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1401E8u;
    // 0x1401e8: 0xac86002c  sw          $a2, 0x2C($a0)
    ctx->pc = 0x1401e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 6));
    // 0x1401ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1401ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401ECu;
            // 0x1401f0: 0xac850028  sw          $a1, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1400F8u: goto label_1400f8;
            case 0x14011Cu: goto label_14011c;
            case 0x140190u: goto label_140190;
            case 0x140194u: goto label_140194;
            case 0x1401C8u: goto label_1401c8;
            case 0x1401CCu: goto label_1401cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1401F4u;
    // 0x1401f4: 0x0  nop
    ctx->pc = 0x1401f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
