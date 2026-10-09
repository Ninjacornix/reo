#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00209FB0
// Address: 0x209fb0 - 0x20a0e0
void sub_00209FB0_0x209fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00209FB0_0x209fb0");
#endif

    switch (ctx->pc) {
        case 0x209ffcu: goto label_209ffc;
        default: break;
    }

    ctx->pc = 0x209fb0u;

    // 0x209fb0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x209fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x209fb4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x209fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x209fb8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x209fb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x209fbc: 0x32020fff  andi        $v0, $s0, 0xFFF
    ctx->pc = 0x209fbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)4095);
    // 0x209fc0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x209FC0u;
    {
        const bool branch_taken_0x209fc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x209FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x209FC0u;
            // 0x209fc4: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x209fc0) {
            ctx->pc = 0x209FE0u;
            goto label_209fe0;
        }
    }
    ctx->pc = 0x209FC8u;
    // 0x209fc8: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x209fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x209fcc: 0x2603ffff  addiu       $v1, $s0, -0x1
    ctx->pc = 0x209fccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x209fd0: 0x3442fffe  ori         $v0, $v0, 0xFFFE
    ctx->pc = 0x209fd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
    // 0x209fd4: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x209fd4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x209fd8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x209FD8u;
    {
        const bool branch_taken_0x209fd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x209FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x209FD8u;
            // 0x209fdc: 0x3c047000  lui         $a0, 0x7000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x209fd8) {
            ctx->pc = 0x209FE8u;
            goto label_209fe8;
        }
    }
    ctx->pc = 0x209FE0u;
label_209fe0:
    // 0x209fe0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x209FE0u;
    {
        const bool branch_taken_0x209fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x209FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x209FE0u;
            // 0x209fe4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x209fe0) {
            ctx->pc = 0x20A0D0u;
            goto label_20a0d0;
        }
    }
    ctx->pc = 0x209FE8u;
label_209fe8:
    // 0x209fe8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x209fe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x209fec: 0x34844000  ori         $a0, $a0, 0x4000
    ctx->pc = 0x209fecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16384);
    // 0x209ff0: 0x37a60004  ori         $a2, $sp, 0x4
    ctx->pc = 0x209ff0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
    // 0x209ff4: 0xc01d456  jal         func_075158
    ctx->pc = 0x209FF4u;
    SET_GPR_U32(ctx, 31, 0x209FFCu);
    ctx->pc = 0x209FF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x209FF4u;
            // 0x209ff8: 0x37a70008  ori         $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
    ctx->pc = 0x75158u;
    {
        auto targetFn = runtime->lookupFunction(0x75158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x209FFCu; }
        if (ctx->pc != 0x209FFCu) { return; }
    }
    ctx->pc = 0x209FFCu;
label_209ffc:
    // 0x209ffc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x209ffcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a000: 0x4a10009  bgez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x20A000u;
    {
        const bool branch_taken_0x20a000 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x20a000) {
            ctx->pc = 0x20A028u;
            goto label_20a028;
        }
    }
    ctx->pc = 0x20A008u;
    // 0x20a008: 0x12000031  beqz        $s0, . + 4 + (0x31 << 2)
    ctx->pc = 0x20A008u;
    {
        const bool branch_taken_0x20a008 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A008u;
            // 0x20a00c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a008) {
            ctx->pc = 0x20A0D0u;
            goto label_20a0d0;
        }
    }
    ctx->pc = 0x20A010u;
    // 0x20a010: 0x40053000  mfc0        $a1, Wired
    ctx->pc = 0x20a010u;
    SET_GPR_S32(ctx, 5, (int32_t)ctx->cop0_wired);
    // 0x20a014: 0x24a20001  addiu       $v0, $a1, 0x1
    ctx->pc = 0x20a014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x20a018: 0x40823000  mtc0        $v0, Wired
    ctx->pc = 0x20a018u;
    ctx->cop0_wired = GPR_U32(ctx, 2) & 0x3F; ctx->cop0_random = 47;
    // 0x20a01c: 0x40f  sync.p
    ctx->pc = 0x20a01cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20a020: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x20A020u;
    {
        const bool branch_taken_0x20a020 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x20a020) {
            ctx->pc = 0x20A070u;
            goto label_20a070;
        }
    }
    ctx->pc = 0x20A028u;
label_20a028:
    // 0x20a028: 0x16000011  bnez        $s0, . + 4 + (0x11 << 2)
    ctx->pc = 0x20A028u;
    {
        const bool branch_taken_0x20a028 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A028u;
            // 0x20a02c: 0x24a2ffff  addiu       $v0, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a028) {
            ctx->pc = 0x20A070u;
            goto label_20a070;
        }
    }
    ctx->pc = 0x20A030u;
    // 0x20a030: 0x3c03e001  lui         $v1, 0xE001
    ctx->pc = 0x20a030u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57345 << 16));
    // 0x20a034: 0x21340  sll         $v0, $v0, 13
    ctx->pc = 0x20a034u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 13));
    // 0x20a038: 0x433021  addu        $a2, $v0, $v1
    ctx->pc = 0x20a038u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x20a03c: 0x40023000  mfc0        $v0, Wired
    ctx->pc = 0x20a03cu;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_wired);
    // 0x20a040: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x20a040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x20a044: 0x40823000  mtc0        $v0, Wired
    ctx->pc = 0x20a044u;
    ctx->cop0_wired = GPR_U32(ctx, 2) & 0x3F; ctx->cop0_random = 47;
    // 0x20a048: 0x40850000  mtc0        $a1, Index
    ctx->pc = 0x20a048u;
    ctx->cop0_index = GPR_U32(ctx, 5) & 0x3F;
    // 0x20a04c: 0x40802800  mtc0        $zero, PageMask
    ctx->pc = 0x20a04cu;
    ctx->cop0_pagemask = GPR_U32(ctx, 0) & 0x01FFE000;
    // 0x20a050: 0x40865000  mtc0        $a2, EntryHi
    ctx->pc = 0x20a050u;
    ctx->cop0_entryhi = GPR_U32(ctx, 6) & 0xC00000FF;
    // 0x20a054: 0x40801000  mtc0        $zero, EntryLo0
    ctx->pc = 0x20a054u;
    ctx->cop0_entrylo0 = GPR_U32(ctx, 0) & 0x3FFFFFFF;
    // 0x20a058: 0x40801800  mtc0        $zero, EntryLo1
    ctx->pc = 0x20a058u;
    ctx->cop0_entrylo1 = GPR_U32(ctx, 0) & 0x3FFFFFFF;
    // 0x20a05c: 0x40f  sync.p
    ctx->pc = 0x20a05cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20a060: 0x42000002  tlbwi
    ctx->pc = 0x20a060u;
    runtime->handleTLBWI(rdram, ctx);
    // 0x20a064: 0x40f  sync.p
    ctx->pc = 0x20a064u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20a068: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x20A068u;
    {
        const bool branch_taken_0x20a068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A06Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A068u;
            // 0x20a06c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a068) {
            ctx->pc = 0x20A0D0u;
            goto label_20a0d0;
        }
    }
    ctx->pc = 0x20A070u;
label_20a070:
    // 0x20a070: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x20a070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x20a074: 0x26041000  addiu       $a0, $s0, 0x1000
    ctx->pc = 0x20a074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4096));
    // 0x20a078: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x20a078u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x20a07c: 0x3c067000  lui         $a2, 0x7000
    ctx->pc = 0x20a07cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)28672 << 16));
    // 0x20a080: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x20a080u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x20a084: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x20a084u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x20a088: 0x2021024  and         $v0, $s0, $v0
    ctx->pc = 0x20a088u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x20a08c: 0x42182  srl         $a0, $a0, 6
    ctx->pc = 0x20a08cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
    // 0x20a090: 0x21182  srl         $v0, $v0, 6
    ctx->pc = 0x20a090u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x20a094: 0x3484001f  ori         $a0, $a0, 0x1F
    ctx->pc = 0x20a094u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)31);
    // 0x20a098: 0x3442001f  ori         $v0, $v0, 0x1F
    ctx->pc = 0x20a098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31);
    // 0x20a09c: 0x34c64000  ori         $a2, $a2, 0x4000
    ctx->pc = 0x20a09cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16384);
    // 0x20a0a0: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x20a0a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x20a0a4: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x20a0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
    // 0x20a0a8: 0x40850000  mtc0        $a1, Index
    ctx->pc = 0x20a0a8u;
    ctx->cop0_index = GPR_U32(ctx, 5) & 0x3F;
    // 0x20a0ac: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x20a0acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a0b0: 0x40832800  mtc0        $v1, PageMask
    ctx->pc = 0x20a0b0u;
    ctx->cop0_pagemask = GPR_U32(ctx, 3) & 0x01FFE000;
    // 0x20a0b4: 0x40865000  mtc0        $a2, EntryHi
    ctx->pc = 0x20a0b4u;
    ctx->cop0_entryhi = GPR_U32(ctx, 6) & 0xC00000FF;
    // 0x20a0b8: 0x40821000  mtc0        $v0, EntryLo0
    ctx->pc = 0x20a0b8u;
    ctx->cop0_entrylo0 = GPR_U32(ctx, 2) & 0x3FFFFFFF;
    // 0x20a0bc: 0x40841800  mtc0        $a0, EntryLo1
    ctx->pc = 0x20a0bcu;
    ctx->cop0_entrylo1 = GPR_U32(ctx, 4) & 0x3FFFFFFF;
    // 0x20a0c0: 0x40f  sync.p
    ctx->pc = 0x20a0c0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20a0c4: 0x42000002  tlbwi
    ctx->pc = 0x20a0c4u;
    runtime->handleTLBWI(rdram, ctx);
    // 0x20a0c8: 0x40f  sync.p
    ctx->pc = 0x20a0c8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20a0cc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x20a0ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_20a0d0:
    // 0x20a0d0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x20a0d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20a0d4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x20a0d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20a0d8: 0x3e00008  jr          $ra
    ctx->pc = 0x20A0D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20A0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A0D8u;
            // 0x20a0dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x209FE0u: goto label_209fe0;
            case 0x209FE8u: goto label_209fe8;
            case 0x209FFCu: goto label_209ffc;
            case 0x20A028u: goto label_20a028;
            case 0x20A070u: goto label_20a070;
            case 0x20A0D0u: goto label_20a0d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A0E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
