#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150000
// Address: 0x150000 - 0x150110
void sub_00150000_0x150000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150000_0x150000");
#endif

    switch (ctx->pc) {
        case 0x150058u: goto label_150058;
        case 0x150090u: goto label_150090;
        case 0x1500a0u: goto label_1500a0;
        case 0x1500a8u: goto label_1500a8;
        default: break;
    }

    ctx->pc = 0x150000u;

    // 0x150000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150004: 0x80782d  daddu       $t7, $a0, $zero
    ctx->pc = 0x150004u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150008: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15000c: 0xa0c82d  daddu       $t9, $a1, $zero
    ctx->pc = 0x15000cu;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150010: 0xc0702d  daddu       $t6, $a2, $zero
    ctx->pc = 0x150010u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150014: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x150014u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150018: 0x8de30004  lw          $v1, 0x4($t7)
    ctx->pc = 0x150018u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 4)));
    // 0x15001c: 0x8de20008  lw          $v0, 0x8($t7)
    ctx->pc = 0x15001cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 8)));
    // 0x150020: 0x28650000  slti        $a1, $v1, 0x0
    ctx->pc = 0x150020u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x150024: 0x2467000f  addiu       $a3, $v1, 0xF
    ctx->pc = 0x150024u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x150028: 0x2446001f  addiu       $a2, $v0, 0x1F
    ctx->pc = 0x150028u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x15002c: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x15002cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x150030: 0xe5180b  movn        $v1, $a3, $a1
    ctx->pc = 0x150030u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x150034: 0x8de50000  lw          $a1, 0x0($t7)
    ctx->pc = 0x150034u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x150038: 0xc4100b  movn        $v0, $a2, $a0
    ctx->pc = 0x150038u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x15003c: 0x3c103  sra         $t8, $v1, 4
    ctx->pc = 0x15003cu;
    SET_GPR_S32(ctx, 24, SRA32(GPR_S32(ctx, 3), 4));
    // 0x150040: 0x24943  sra         $t1, $v0, 5
    ctx->pc = 0x150040u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 2), 5));
    // 0x150044: 0x8f2c000c  lw          $t4, 0xC($t9)
    ctx->pc = 0x150044u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x150048: 0x1b00002d  blez        $t8, . + 4 + (0x2D << 2)
    ctx->pc = 0x150048u;
    {
        const bool branch_taken_0x150048 = (GPR_S64(ctx, 24) <= 0);
        ctx->pc = 0x15004Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150048u;
            // 0x15004c: 0x98040  sll         $s0, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150048) {
            ctx->pc = 0x150100u;
            goto label_150100;
        }
    }
    ctx->pc = 0x150050u;
    // 0x150050: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x150050u;
    {
        const bool branch_taken_0x150050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150050u;
            // 0x150054: 0x12d2018  mult        $a0, $t1, $t5 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x150050) {
            ctx->pc = 0x150060u;
            goto label_150060;
        }
    }
    ctx->pc = 0x150058u;
label_150058:
    // 0x150058: 0x12d2018  mult        $a0, $t1, $t5
    ctx->pc = 0x150058u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x15005c: 0x0  nop
    ctx->pc = 0x15005cu;
    // NOP
label_150060:
    // 0x150060: 0x2091821  addu        $v1, $s0, $t1
    ctx->pc = 0x150060u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 9)));
    // 0x150064: 0x319c0  sll         $v1, $v1, 7
    ctx->pc = 0x150064u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
    // 0x150068: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x150068u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15006c: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x15006cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x150070: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x150070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x150074: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x150074u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x150078: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x150078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x15007c: 0x1920001c  blez        $t1, . + 4 + (0x1C << 2)
    ctx->pc = 0x15007Cu;
    {
        const bool branch_taken_0x15007c = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x150080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15007Cu;
            // 0x150080: 0x453021  addu        $a2, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15007c) {
            ctx->pc = 0x1500F0u;
            goto label_1500f0;
        }
    }
    ctx->pc = 0x150084u;
    // 0x150084: 0xd3980  sll         $a3, $t5, 6
    ctx->pc = 0x150084u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 13), 6));
    // 0x150088: 0xc5900  sll         $t3, $t4, 4
    ctx->pc = 0x150088u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 12), 4));
    // 0x15008c: 0x0  nop
    ctx->pc = 0x15008cu;
    // NOP
label_150090:
    // 0x150090: 0x8f220000  lw          $v0, 0x0($t9)
    ctx->pc = 0x150090u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x150094: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x150094u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150098: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x150098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x15009c: 0x24440003  addiu       $a0, $v0, 0x3
    ctx->pc = 0x15009cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 3));
label_1500a0:
    // 0x1500a0: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x1500a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1500a4: 0x0  nop
    ctx->pc = 0x1500a4u;
    // NOP
label_1500a8:
    // 0x1500a8: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x1500a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1500ac: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1500acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1500b0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1500b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1500b4: 0x1c31821  addu        $v1, $t6, $v1
    ctx->pc = 0x1500b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 3)));
    // 0x1500b8: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x1500b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1500bc: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1500bcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1500c0: 0x4a1fff9  bgez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1500C0u;
    {
        const bool branch_taken_0x1500c0 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1500C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1500C0u;
            // 0x1500c4: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1500c0) {
            ctx->pc = 0x1500A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1500a8;
        }
    }
    ctx->pc = 0x1500C8u;
    // 0x1500c8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1500c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1500cc: 0x8c1021  addu        $v0, $a0, $t4
    ctx->pc = 0x1500ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1500d0: 0x29030010  slti        $v1, $t0, 0x10
    ctx->pc = 0x1500d0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1500d4: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1500D4u;
    {
        const bool branch_taken_0x1500d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1500D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1500D4u;
            // 0x1500d8: 0x2444ffc0  addiu       $a0, $v0, -0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1500d4) {
            ctx->pc = 0x1500A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1500a0;
        }
    }
    ctx->pc = 0x1500DCu;
    // 0x1500dc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1500dcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1500e0: 0x24c60080  addiu       $a2, $a2, 0x80
    ctx->pc = 0x1500e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
    // 0x1500e4: 0x149102a  slt         $v0, $t2, $t1
    ctx->pc = 0x1500e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1500e8: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1500E8u;
    {
        const bool branch_taken_0x1500e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1500ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1500E8u;
            // 0x1500ec: 0xeb3821  addu        $a3, $a3, $t3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1500e8) {
            ctx->pc = 0x150090u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150090;
        }
    }
    ctx->pc = 0x1500F0u;
label_1500f0:
    // 0x1500f0: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x1500f0u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x1500f4: 0x1b8102a  slt         $v0, $t5, $t8
    ctx->pc = 0x1500f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 24)) ? 1 : 0);
    // 0x1500f8: 0x5440ffd7  bnel        $v0, $zero, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1500F8u;
    {
        const bool branch_taken_0x1500f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1500f8) {
            ctx->pc = 0x1500FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1500F8u;
            // 0x1500fc: 0x8de50000  lw          $a1, 0x0($t7) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x150058u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150058;
        }
    }
    ctx->pc = 0x150100u;
label_150100:
    // 0x150100: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150100u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150104: 0x3e00008  jr          $ra
    ctx->pc = 0x150104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150104u;
            // 0x150108: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150058u: goto label_150058;
            case 0x150060u: goto label_150060;
            case 0x150090u: goto label_150090;
            case 0x1500A0u: goto label_1500a0;
            case 0x1500A8u: goto label_1500a8;
            case 0x1500F0u: goto label_1500f0;
            case 0x150100u: goto label_150100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15010Cu;
    // 0x15010c: 0x0  nop
    ctx->pc = 0x15010cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
