#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159FB0
// Address: 0x159fb0 - 0x15a270
void sub_00159FB0_0x159fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159FB0_0x159fb0");
#endif

    switch (ctx->pc) {
        case 0x15a00cu: goto label_15a00c;
        case 0x15a220u: goto label_15a220;
        case 0x15a238u: goto label_15a238;
        case 0x15a250u: goto label_15a250;
        default: break;
    }

    ctx->pc = 0x159fb0u;

    // 0x159fb0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x159fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x159fb4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x159fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x159fb8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x159fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x159fbc: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x159fbcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x159fc0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x159fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x159fc4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x159fc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159fc8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x159fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x159fcc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x159fccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159fd0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x159fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x159fd4: 0x26330348  addiu       $s3, $s1, 0x348
    ctx->pc = 0x159fd4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 840));
    // 0x159fd8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x159fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x159fdc: 0x263001d0  addiu       $s0, $s1, 0x1D0
    ctx->pc = 0x159fdcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 464));
    // 0x159fe0: 0xae220384  sw          $v0, 0x384($s1)
    ctx->pc = 0x159fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 900), GPR_U32(ctx, 2));
    // 0x159fe4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x159fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x159fe8: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x159fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x159fec: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x159fecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x159ff0: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x159ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x159ff4: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x159ff4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159ff8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x159ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x159ffc: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x159ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x15a000: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15a000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a004: 0x40f809  jalr        $v0
    ctx->pc = 0x15A004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A00Cu);
        ctx->pc = 0x15A008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A004u;
            // 0x15a008: 0xae030030  sw          $v1, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A00Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A00Cu: goto label_15a00c;
            case 0x15A0A0u: goto label_15a0a0;
            case 0x15A118u: goto label_15a118;
            case 0x15A120u: goto label_15a120;
            case 0x15A160u: goto label_15a160;
            case 0x15A16Cu: goto label_15a16c;
            case 0x15A1C0u: goto label_15a1c0;
            case 0x15A1C8u: goto label_15a1c8;
            case 0x15A1E8u: goto label_15a1e8;
            case 0x15A1ECu: goto label_15a1ec;
            case 0x15A220u: goto label_15a220;
            case 0x15A238u: goto label_15a238;
            case 0x15A250u: goto label_15a250;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A00Cu; }
            if (ctx->pc != 0x15A00Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15A00Cu;
label_15a00c:
    // 0x15a00c: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x15a00cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15a010: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x15a010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x15a014: 0x625024  and         $t2, $v1, $v0
    ctx->pc = 0x15a014u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x15a018: 0x6a1823  subu        $v1, $v1, $t2
    ctx->pc = 0x15a018u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x15a01c: 0x254a0004  addiu       $t2, $t2, 0x4
    ctx->pc = 0x15a01cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
    // 0x15a020: 0x81490000  lb          $t1, 0x0($t2)
    ctx->pc = 0x15a020u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a024: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a024u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a028: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a028u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a02c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a02cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a030: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a030u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a034: 0x91440000  lbu         $a0, 0x0($t2)
    ctx->pc = 0x15a034u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a038: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a038u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15a03c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a03cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a040: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a040u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a044: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a044u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a048: 0x358c0  sll         $t3, $v1, 3
    ctx->pc = 0x15a048u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x15a04c: 0x1244825  or          $t1, $t1, $a0
    ctx->pc = 0x15a04cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 4));
    // 0x15a050: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a050u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a054: 0x29630020  slti        $v1, $t3, 0x20
    ctx->pc = 0x15a054u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a058: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a058u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15a05c: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x15A05Cu;
    {
        const bool branch_taken_0x15a05c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A05Cu;
            // 0x15a060: 0x254a0001  addiu       $t2, $t2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a05c) {
            ctx->pc = 0x15A0A0u;
            goto label_15a0a0;
        }
    }
    ctx->pc = 0x15A064u;
    // 0x15a064: 0x81490000  lb          $t1, 0x0($t2)
    ctx->pc = 0x15a064u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a068: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a068u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a06c: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a06cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a070: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a070u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a074: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a074u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a078: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x15a078u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a07c: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a07cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15a080: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a080u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a084: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a084u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a088: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a088u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a08c: 0x1234825  or          $t1, $t1, $v1
    ctx->pc = 0x15a08cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
    // 0x15a090: 0x256bffe0  addiu       $t3, $t3, -0x20
    ctx->pc = 0x15a090u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967264));
    // 0x15a094: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a094u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a098: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a098u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a09c: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a09cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
label_15a0a0:
    // 0x15a0a0: 0x1691804  sllv        $v1, $t1, $t3
    ctx->pc = 0x15a0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 11) & 0x1F));
    // 0x15a0a4: 0x39620000  xori        $v0, $t3, 0x0
    ctx->pc = 0x15a0a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) ^ (uint64_t)(uint16_t)0);
    // 0x15a0a8: 0x120602d  daddu       $t4, $t1, $zero
    ctx->pc = 0x15a0a8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a0ac: 0x81490000  lb          $t1, 0x0($t2)
    ctx->pc = 0x15a0acu;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a0b0: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a0b0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a0b4: 0x62600b  movn        $t4, $v1, $v0
    ctx->pc = 0x15a0b4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 12, GPR_VEC(ctx, 3));
    // 0x15a0b8: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a0b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a0bc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a0bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a0c0: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a0c0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a0c4: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x15a0c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a0c8: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a0c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15a0cc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a0ccu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a0d0: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a0d0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a0d4: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a0d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a0d8: 0x1234825  or          $t1, $t1, $v1
    ctx->pc = 0x15a0d8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
    // 0x15a0dc: 0x29640007  slti        $a0, $t3, 0x7
    ctx->pc = 0x15a0dcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)7) ? 1 : 0);
    // 0x15a0e0: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a0e0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a0e4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a0e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a0e8: 0x1480001d  bnez        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x15A0E8u;
    {
        const bool branch_taken_0x15a0e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A0E8u;
            // 0x15a0ec: 0x1224825  or          $t1, $t1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a0e8) {
            ctx->pc = 0x15A160u;
            goto label_15a160;
        }
    }
    ctx->pc = 0x15A0F0u;
    // 0x15a0f0: 0x256bfff9  addiu       $t3, $t3, -0x7
    ctx->pc = 0x15a0f0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967289));
    // 0x15a0f4: 0x11600008  beqz        $t3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15A0F4u;
    {
        const bool branch_taken_0x15a0f4 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A0F4u;
            // 0x15a0f8: 0x24020019  addiu       $v0, $zero, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a0f4) {
            ctx->pc = 0x15A118u;
            goto label_15a118;
        }
    }
    ctx->pc = 0x15A0FCu;
    // 0x15a0fc: 0x4b1023  subu        $v0, $v0, $t3
    ctx->pc = 0x15a0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x15a100: 0x491006  srlv        $v0, $t1, $v0
    ctx->pc = 0x15a100u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a104: 0x1826025  or          $t4, $t4, $v0
    ctx->pc = 0x15a104u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | GPR_U64(ctx, 2));
    // 0x15a108: 0xc21c2  srl         $a0, $t4, 7
    ctx->pc = 0x15a108u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 12), 7));
    // 0x15a10c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15A10Cu;
    {
        const bool branch_taken_0x15a10c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A10Cu;
            // 0x15a110: 0x1696004  sllv        $t4, $t1, $t3 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 11) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a10c) {
            ctx->pc = 0x15A120u;
            goto label_15a120;
        }
    }
    ctx->pc = 0x15A114u;
    // 0x15a114: 0x0  nop
    ctx->pc = 0x15a114u;
    // NOP
label_15a118:
    // 0x15a118: 0xc21c2  srl         $a0, $t4, 7
    ctx->pc = 0x15a118u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 12), 7));
    // 0x15a11c: 0x120602d  daddu       $t4, $t1, $zero
    ctx->pc = 0x15a11cu;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
label_15a120:
    // 0x15a120: 0x81490000  lb          $t1, 0x0($t2)
    ctx->pc = 0x15a120u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a124: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a124u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a128: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a128u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a12c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a12cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a130: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a130u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a134: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x15a134u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a138: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x15a138u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15a13c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a13cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a140: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a140u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a144: 0x91420000  lbu         $v0, 0x0($t2)
    ctx->pc = 0x15a144u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x15a148: 0x1234825  or          $t1, $t1, $v1
    ctx->pc = 0x15a148u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
    // 0x15a14c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x15a14cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x15a150: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x15a150u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15a154: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15A154u;
    {
        const bool branch_taken_0x15a154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A154u;
            // 0x15a158: 0x1224825  or          $t1, $t1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a154) {
            ctx->pc = 0x15A16Cu;
            goto label_15a16c;
        }
    }
    ctx->pc = 0x15A15Cu;
    // 0x15a15c: 0x0  nop
    ctx->pc = 0x15a15cu;
    // NOP
label_15a160:
    // 0x15a160: 0xc21c2  srl         $a0, $t4, 7
    ctx->pc = 0x15a160u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 12), 7));
    // 0x15a164: 0xc6640  sll         $t4, $t4, 25
    ctx->pc = 0x15a164u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 25));
    // 0x15a168: 0x256b0019  addiu       $t3, $t3, 0x19
    ctx->pc = 0x15a168u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 25));
label_15a16c:
    // 0x15a16c: 0x3088003f  andi        $t0, $a0, 0x3F
    ctx->pc = 0x15a16cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)63);
    // 0x15a170: 0x42182  srl         $a0, $a0, 6
    ctx->pc = 0x15a170u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
    // 0x15a174: 0x3087003f  andi        $a3, $a0, 0x3F
    ctx->pc = 0x15a174u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)63);
    // 0x15a178: 0x421c2  srl         $a0, $a0, 7
    ctx->pc = 0x15a178u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 7));
    // 0x15a17c: 0x3086003f  andi        $a2, $a0, 0x3F
    ctx->pc = 0x15a17cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)63);
    // 0x15a180: 0x42182  srl         $a0, $a0, 6
    ctx->pc = 0x15a180u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
    // 0x15a184: 0x41142  srl         $v0, $a0, 5
    ctx->pc = 0x15a184u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 5));
    // 0x15a188: 0x3083001f  andi        $v1, $a0, 0x1F
    ctx->pc = 0x15a188u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)31);
    // 0x15a18c: 0x2405001f  addiu       $a1, $zero, 0x1F
    ctx->pc = 0x15a18cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x15a190: 0xc27c2  srl         $a0, $t4, 31
    ctx->pc = 0x15a190u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 12), 31));
    // 0x15a194: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x15a194u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
    // 0x15a198: 0xae08002c  sw          $t0, 0x2C($s0)
    ctx->pc = 0x15a198u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 8));
    // 0x15a19c: 0xae070028  sw          $a3, 0x28($s0)
    ctx->pc = 0x15a19cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 7));
    // 0x15a1a0: 0xae060024  sw          $a2, 0x24($s0)
    ctx->pc = 0x15a1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 6));
    // 0x15a1a4: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x15a1a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x15a1a8: 0x15650005  bne         $t3, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x15A1A8u;
    {
        const bool branch_taken_0x15a1a8 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 5));
        ctx->pc = 0x15A1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A1A8u;
            // 0x15a1ac: 0xae240288  sw          $a0, 0x288($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 648), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a1a8) {
            ctx->pc = 0x15A1C0u;
            goto label_15a1c0;
        }
    }
    ctx->pc = 0x15A1B0u;
    // 0x15a1b0: 0x120602d  daddu       $t4, $t1, $zero
    ctx->pc = 0x15a1b0u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a1b4: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x15a1b4u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a1b8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15A1B8u;
    {
        const bool branch_taken_0x15a1b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A1B8u;
            // 0x15a1bc: 0x254a0004  addiu       $t2, $t2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a1b8) {
            ctx->pc = 0x15A1C8u;
            goto label_15a1c8;
        }
    }
    ctx->pc = 0x15A1C0u;
label_15a1c0:
    // 0x15a1c0: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x15a1c0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x15a1c4: 0xc6040  sll         $t4, $t4, 1
    ctx->pc = 0x15a1c4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
label_15a1c8:
    // 0x15a1c8: 0xc17c2  srl         $v0, $t4, 31
    ctx->pc = 0x15a1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 12), 31));
    // 0x15a1cc: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x15a1ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x15a1d0: 0x15630005  bne         $t3, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x15A1D0u;
    {
        const bool branch_taken_0x15a1d0 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 3));
        ctx->pc = 0x15A1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A1D0u;
            // 0x15a1d4: 0xae22028c  sw          $v0, 0x28C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 652), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a1d0) {
            ctx->pc = 0x15A1E8u;
            goto label_15a1e8;
        }
    }
    ctx->pc = 0x15A1D8u;
    // 0x15a1d8: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x15a1d8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a1dc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15A1DCu;
    {
        const bool branch_taken_0x15a1dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A1DCu;
            // 0x15a1e0: 0x254a0004  addiu       $t2, $t2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a1dc) {
            ctx->pc = 0x15A1ECu;
            goto label_15a1ec;
        }
    }
    ctx->pc = 0x15A1E4u;
    // 0x15a1e4: 0x0  nop
    ctx->pc = 0x15a1e4u;
    // NOP
label_15a1e8:
    // 0x15a1e8: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x15a1e8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
label_15a1ec:
    // 0x15a1ec: 0x31620007  andi        $v0, $t3, 0x7
    ctx->pc = 0x15a1ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)7);
    // 0x15a1f0: 0x8e230348  lw          $v1, 0x348($s1)
    ctx->pc = 0x15a1f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 840)));
    // 0x15a1f4: 0x1622823  subu        $a1, $t3, $v0
    ctx->pc = 0x15a1f4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x15a1f8: 0xae220350  sw          $v0, 0x350($s1)
    ctx->pc = 0x15a1f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 848), GPR_U32(ctx, 2));
    // 0x15a1fc: 0x24a50007  addiu       $a1, $a1, 0x7
    ctx->pc = 0x15a1fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x15a200: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15a200u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a204: 0x528c3  sra         $a1, $a1, 3
    ctx->pc = 0x15a204u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 3));
    // 0x15a208: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15a208u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a20c: 0x1452821  addu        $a1, $t2, $a1
    ctx->pc = 0x15a20cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
    // 0x15a210: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x15a210u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a214: 0x24a5fff8  addiu       $a1, $a1, -0x8
    ctx->pc = 0x15a214u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967288));
    // 0x15a218: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15A218u;
    SET_GPR_U32(ctx, 31, 0x15A220u);
    ctx->pc = 0x15A21Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15A218u;
            // 0x15a21c: 0xa32823  subu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A220u; }
        if (ctx->pc != 0x15A220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A220u; }
        if (ctx->pc != 0x15A220u) { return; }
    }
    ctx->pc = 0x15A220u;
label_15a220:
    // 0x15a220: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x15a220u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15a224: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x15a224u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a228: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15a228u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a22c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15a22cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15a230: 0x40f809  jalr        $v0
    ctx->pc = 0x15A230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A238u);
        ctx->pc = 0x15A234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A230u;
            // 0x15a234: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A238u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A00Cu: goto label_15a00c;
            case 0x15A0A0u: goto label_15a0a0;
            case 0x15A118u: goto label_15a118;
            case 0x15A120u: goto label_15a120;
            case 0x15A160u: goto label_15a160;
            case 0x15A16Cu: goto label_15a16c;
            case 0x15A1C0u: goto label_15a1c0;
            case 0x15A1C8u: goto label_15a1c8;
            case 0x15A1E8u: goto label_15a1e8;
            case 0x15A1ECu: goto label_15a1ec;
            case 0x15A220u: goto label_15a220;
            case 0x15A238u: goto label_15a238;
            case 0x15A250u: goto label_15a250;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A238u; }
            if (ctx->pc != 0x15A238u) { return; }
        }
        }
    }
    ctx->pc = 0x15A238u;
label_15a238:
    // 0x15a238: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x15a238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15a23c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15a23cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a240: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15a240u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a244: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15a244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15a248: 0x40f809  jalr        $v0
    ctx->pc = 0x15A248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A250u);
        ctx->pc = 0x15A24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A248u;
            // 0x15a24c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A250u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A00Cu: goto label_15a00c;
            case 0x15A0A0u: goto label_15a0a0;
            case 0x15A118u: goto label_15a118;
            case 0x15A120u: goto label_15a120;
            case 0x15A160u: goto label_15a160;
            case 0x15A16Cu: goto label_15a16c;
            case 0x15A1C0u: goto label_15a1c0;
            case 0x15A1C8u: goto label_15a1c8;
            case 0x15A1E8u: goto label_15a1e8;
            case 0x15A1ECu: goto label_15a1ec;
            case 0x15A220u: goto label_15a220;
            case 0x15A238u: goto label_15a238;
            case 0x15A250u: goto label_15a250;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A250u; }
            if (ctx->pc != 0x15A250u) { return; }
        }
        }
    }
    ctx->pc = 0x15A250u;
label_15a250:
    // 0x15a250: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15a250u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a254: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15a254u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15a258: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15a258u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15a25c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15a25cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15a260: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x15a260u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15a264: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x15a264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15a268: 0x3e00008  jr          $ra
    ctx->pc = 0x15A268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15A26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A268u;
            // 0x15a26c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A00Cu: goto label_15a00c;
            case 0x15A0A0u: goto label_15a0a0;
            case 0x15A118u: goto label_15a118;
            case 0x15A120u: goto label_15a120;
            case 0x15A160u: goto label_15a160;
            case 0x15A16Cu: goto label_15a16c;
            case 0x15A1C0u: goto label_15a1c0;
            case 0x15A1C8u: goto label_15a1c8;
            case 0x15A1E8u: goto label_15a1e8;
            case 0x15A1ECu: goto label_15a1ec;
            case 0x15A220u: goto label_15a220;
            case 0x15A238u: goto label_15a238;
            case 0x15A250u: goto label_15a250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15A270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
