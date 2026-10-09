#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0030
// Address: 0x1d0030 - 0x1d02b0
void sub_001D0030_0x1d0030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0030_0x1d0030");
#endif

    switch (ctx->pc) {
        case 0x1d0048u: goto label_1d0048;
        case 0x1d00d0u: goto label_1d00d0;
        case 0x1d00e0u: goto label_1d00e0;
        case 0x1d00ecu: goto label_1d00ec;
        case 0x1d010cu: goto label_1d010c;
        case 0x1d0134u: goto label_1d0134;
        case 0x1d0184u: goto label_1d0184;
        case 0x1d01a4u: goto label_1d01a4;
        case 0x1d01c4u: goto label_1d01c4;
        case 0x1d01e0u: goto label_1d01e0;
        case 0x1d0228u: goto label_1d0228;
        case 0x1d0230u: goto label_1d0230;
        case 0x1d024cu: goto label_1d024c;
        case 0x1d028cu: goto label_1d028c;
        default: break;
    }

    ctx->pc = 0x1d0030u;

label_1d0030:
    // 0x1d0030: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d0030u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d0034: 0x3c080034  lui         $t0, 0x34
    ctx->pc = 0x1d0034u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)52 << 16));
    // 0x1d0038: 0x25291430  addiu       $t1, $t1, 0x1430
    ctx->pc = 0x1d0038u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 5168));
    // 0x1d003c: 0x25081500  addiu       $t0, $t0, 0x1500
    ctx->pc = 0x1d003cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 5376));
    // 0x1d0040: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d0040u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0044: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0044u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1d0048:
    // 0x1d0048: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1d0048u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1d004c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D004Cu;
    {
        const bool branch_taken_0x1d004c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d004c) {
            ctx->pc = 0x1D006Cu;
            goto label_1d006c;
        }
    }
    ctx->pc = 0x1D0054u;
    // 0x1d0054: 0x91230008  lbu         $v1, 0x8($t1)
    ctx->pc = 0x1d0054u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1d0058: 0x14660004  bne         $v1, $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0058u;
    {
        const bool branch_taken_0x1d0058 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1d0058) {
            ctx->pc = 0x1D006Cu;
            goto label_1d006c;
        }
    }
    ctx->pc = 0x1D0060u;
    // 0x1d0060: 0x9523000a  lhu         $v1, 0xA($t1)
    ctx->pc = 0x1d0060u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 10)));
    // 0x1d0064: 0xa4830000  sh          $v1, 0x0($a0)
    ctx->pc = 0x1d0064u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d0068: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1d0068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
label_1d006c:
    // 0x1d006c: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1d006cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1d0070: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D0070u;
    {
        const bool branch_taken_0x1d0070 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0070) {
            ctx->pc = 0x1D0090u;
            goto label_1d0090;
        }
    }
    ctx->pc = 0x1D0078u;
    // 0x1d0078: 0x91030010  lbu         $v1, 0x10($t0)
    ctx->pc = 0x1d0078u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x1d007c: 0x14660004  bne         $v1, $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D007Cu;
    {
        const bool branch_taken_0x1d007c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1d007c) {
            ctx->pc = 0x1D0090u;
            goto label_1d0090;
        }
    }
    ctx->pc = 0x1D0084u;
    // 0x1d0084: 0x95030012  lhu         $v1, 0x12($t0)
    ctx->pc = 0x1d0084u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 18)));
    // 0x1d0088: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1d0088u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d008c: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1d008cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
label_1d0090:
    // 0x1d0090: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d0090u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d0094: 0x2529000c  addiu       $t1, $t1, 0xC
    ctx->pc = 0x1d0094u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 12));
    // 0x1d0098: 0x28e30010  slti        $v1, $a3, 0x10
    ctx->pc = 0x1d0098u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d009c: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1D009Cu;
    {
        const bool branch_taken_0x1d009c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D00A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D009Cu;
            // 0x1d00a0: 0x25080014  addiu       $t0, $t0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d009c) {
            ctx->pc = 0x1D0048u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0048;
        }
    }
    ctx->pc = 0x1D00A4u;
    // 0x1d00a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D00A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0030u: goto label_1d0030;
            case 0x1D0048u: goto label_1d0048;
            case 0x1D006Cu: goto label_1d006c;
            case 0x1D0090u: goto label_1d0090;
            case 0x1D00D0u: goto label_1d00d0;
            case 0x1D00E0u: goto label_1d00e0;
            case 0x1D00ECu: goto label_1d00ec;
            case 0x1D010Cu: goto label_1d010c;
            case 0x1D0128u: goto label_1d0128;
            case 0x1D0134u: goto label_1d0134;
            case 0x1D014Cu: goto label_1d014c;
            case 0x1D0160u: goto label_1d0160;
            case 0x1D0170u: goto label_1d0170;
            case 0x1D0184u: goto label_1d0184;
            case 0x1D01A4u: goto label_1d01a4;
            case 0x1D01A8u: goto label_1d01a8;
            case 0x1D01C4u: goto label_1d01c4;
            case 0x1D01D0u: goto label_1d01d0;
            case 0x1D01E0u: goto label_1d01e0;
            case 0x1D0228u: goto label_1d0228;
            case 0x1D0230u: goto label_1d0230;
            case 0x1D024Cu: goto label_1d024c;
            case 0x1D026Cu: goto label_1d026c;
            case 0x1D028Cu: goto label_1d028c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D00ACu;
    // 0x1d00ac: 0x0  nop
    ctx->pc = 0x1d00acu;
    // NOP
    // 0x1d00b0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1d00b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1d00b4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1d00b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d00b8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d00b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d00bc: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d00bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d00c0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d00c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d00c4: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d00c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d00c8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D00C8u;
    SET_GPR_U32(ctx, 31, 0x1D00D0u);
    ctx->pc = 0x1D00CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D00C8u;
            // 0x1d00cc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D00D0u; }
        if (ctx->pc != 0x1D00D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D00D0u; }
        if (ctx->pc != 0x1D00D0u) { return; }
    }
    ctx->pc = 0x1D00D0u;
label_1d00d0:
    // 0x1d00d0: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d00d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d00d4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1d00d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d00d8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D00D8u;
    SET_GPR_U32(ctx, 31, 0x1D00E0u);
    ctx->pc = 0x1D00DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D00D8u;
            // 0x1d00dc: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D00E0u; }
        if (ctx->pc != 0x1D00E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D00E0u; }
        if (ctx->pc != 0x1D00E0u) { return; }
    }
    ctx->pc = 0x1D00E0u;
label_1d00e0:
    // 0x1d00e0: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d00e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d00e4: 0xc07400c  jal         func_1D0030
    ctx->pc = 0x1D00E4u;
    SET_GPR_U32(ctx, 31, 0x1D00ECu);
    ctx->pc = 0x1D00E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D00E4u;
            // 0x1d00e8: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D0030u;
    goto label_1d0030;
    ctx->pc = 0x1D00ECu;
label_1d00ec:
    // 0x1d00ec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d00ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d00f0: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1d00f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1d00f4: 0x942443e2  lhu         $a0, 0x43E2($at)
    ctx->pc = 0x1d00f4u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17378)));
    // 0x1d00f8: 0x24638e80  addiu       $v1, $v1, -0x7180
    ctx->pc = 0x1d00f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938240));
    // 0x1d00fc: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1d00fcu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0100: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1d0100u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1d0104: 0x644021  addu        $t0, $v1, $a0
    ctx->pc = 0x1d0104u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d0108: 0x3404ffff  ori         $a0, $zero, 0xFFFF
    ctx->pc = 0x1d0108u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
label_1d010c:
    // 0x1d010c: 0x95070000  lhu         $a3, 0x0($t0)
    ctx->pc = 0x1d010cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1d0110: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x1d0110u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x1d0114: 0x14e40004  bne         $a3, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0114u;
    {
        const bool branch_taken_0x1d0114 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 4));
        ctx->pc = 0x1D0118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0114u;
            // 0x1d0118: 0x25080004  addiu       $t0, $t0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0114) {
            ctx->pc = 0x1D0128u;
            goto label_1d0128;
        }
    }
    ctx->pc = 0x1D011Cu;
    // 0x1d011c: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x1d011cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1d0120: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1D0120u;
    {
        const bool branch_taken_0x1d0120 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0120) {
            ctx->pc = 0x1D0170u;
            goto label_1d0170;
        }
    }
    ctx->pc = 0x1D0128u;
label_1d0128:
    // 0x1d0128: 0x10e40011  beq         $a3, $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D0128u;
    {
        const bool branch_taken_0x1d0128 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D012Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0128u;
            // 0x1d012c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0128) {
            ctx->pc = 0x1D0170u;
            goto label_1d0170;
        }
    }
    ctx->pc = 0x1D0130u;
    // 0x1d0130: 0x93040  sll         $a2, $t1, 1
    ctx->pc = 0x1d0130u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
label_1d0134:
    // 0x1d0134: 0xdd1821  addu        $v1, $a2, $sp
    ctx->pc = 0x1d0134u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 29)));
    // 0x1d0138: 0x24650050  addiu       $a1, $v1, 0x50
    ctx->pc = 0x1d0138u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 80));
    // 0x1d013c: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x1d013cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d0140: 0x14e30002  bne         $a3, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D0140u;
    {
        const bool branch_taken_0x1d0140 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D0144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0140u;
            // 0x1d0144: 0xdd1821  addu        $v1, $a2, $sp (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0140) {
            ctx->pc = 0x1D014Cu;
            goto label_1d014c;
        }
    }
    ctx->pc = 0x1D0148u;
    // 0x1d0148: 0xa4a40000  sh          $a0, 0x0($a1)
    ctx->pc = 0x1d0148u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
label_1d014c:
    // 0x1d014c: 0x24650030  addiu       $a1, $v1, 0x30
    ctx->pc = 0x1d014cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 48));
    // 0x1d0150: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x1d0150u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d0154: 0x14e30002  bne         $a3, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D0154u;
    {
        const bool branch_taken_0x1d0154 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        if (branch_taken_0x1d0154) {
            ctx->pc = 0x1D0160u;
            goto label_1d0160;
        }
    }
    ctx->pc = 0x1D015Cu;
    // 0x1d015c: 0xa4a40000  sh          $a0, 0x0($a1)
    ctx->pc = 0x1d015cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
label_1d0160:
    // 0x1d0160: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1d0160u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1d0164: 0x29230010  slti        $v1, $t1, 0x10
    ctx->pc = 0x1d0164u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d0168: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1D0168u;
    {
        const bool branch_taken_0x1d0168 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D016Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0168u;
            // 0x1d016c: 0x93040  sll         $a2, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0168) {
            ctx->pc = 0x1D0134u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0134;
        }
    }
    ctx->pc = 0x1D0170u;
label_1d0170:
    // 0x1d0170: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1d0170u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1d0174: 0x29430004  slti        $v1, $t2, 0x4
    ctx->pc = 0x1d0174u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d0178: 0x1460ffe4  bnez        $v1, . + 4 + (-0x1C << 2)
    ctx->pc = 0x1D0178u;
    {
        const bool branch_taken_0x1d0178 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D017Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0178u;
            // 0x1d017c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0178) {
            ctx->pc = 0x1D010Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d010c;
        }
    }
    ctx->pc = 0x1D0180u;
    // 0x1d0180: 0x108840  sll         $s1, $s0, 1
    ctx->pc = 0x1d0180u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
label_1d0184:
    // 0x1d0184: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d0184u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d0188: 0x23d2021  addu        $a0, $s1, $sp
    ctx->pc = 0x1d0188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
    // 0x1d018c: 0x94860050  lhu         $a2, 0x50($a0)
    ctx->pc = 0x1d018cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 80)));
    // 0x1d0190: 0x10c30005  beq         $a2, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D0190u;
    {
        const bool branch_taken_0x1d0190 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D0194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0190u;
            // 0x1d0194: 0x23d2021  addu        $a0, $s1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0190) {
            ctx->pc = 0x1D01A8u;
            goto label_1d01a8;
        }
    }
    ctx->pc = 0x1D0198u;
    // 0x1d0198: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1d0198u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d019c: 0xc073b48  jal         func_1CED20
    ctx->pc = 0x1D019Cu;
    SET_GPR_U32(ctx, 31, 0x1D01A4u);
    ctx->pc = 0x1D01A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D019Cu;
            // 0x1d01a0: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CED20u;
    if (runtime->hasFunction(0x1CED20u)) {
        auto targetFn = runtime->lookupFunction(0x1CED20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01A4u; }
        if (ctx->pc != 0x1D01A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CED20_0x1ced20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01A4u; }
        if (ctx->pc != 0x1D01A4u) { return; }
    }
    ctx->pc = 0x1D01A4u;
label_1d01a4:
    // 0x1d01a4: 0x23d2021  addu        $a0, $s1, $sp
    ctx->pc = 0x1d01a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 29)));
label_1d01a8:
    // 0x1d01a8: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d01a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d01ac: 0x24870030  addiu       $a3, $a0, 0x30
    ctx->pc = 0x1d01acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
    // 0x1d01b0: 0x94e40000  lhu         $a0, 0x0($a3)
    ctx->pc = 0x1d01b0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d01b4: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1D01B4u;
    {
        const bool branch_taken_0x1d01b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D01B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01B4u;
            // 0x1d01b8: 0x3085ffff  andi        $a1, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d01b4) {
            ctx->pc = 0x1D01E0u;
            goto label_1d01e0;
        }
    }
    ctx->pc = 0x1D01BCu;
    // 0x1d01bc: 0xc0739e4  jal         func_1CE790
    ctx->pc = 0x1D01BCu;
    SET_GPR_U32(ctx, 31, 0x1D01C4u);
    ctx->pc = 0x1D01C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01BCu;
            // 0x1d01c0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE790u;
    if (runtime->hasFunction(0x1CE790u)) {
        auto targetFn = runtime->lookupFunction(0x1CE790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01C4u; }
        if (ctx->pc != 0x1D01C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE790_0x1ce790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01C4u; }
        if (ctx->pc != 0x1D01C4u) { return; }
    }
    ctx->pc = 0x1D01C4u;
label_1d01c4:
    // 0x1d01c4: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D01C4u;
    {
        const bool branch_taken_0x1d01c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D01C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01C4u;
            // 0x1d01c8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d01c4) {
            ctx->pc = 0x1D01D0u;
            goto label_1d01d0;
        }
    }
    ctx->pc = 0x1D01CCu;
    // 0x1d01cc: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1d01ccu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
label_1d01d0:
    // 0x1d01d0: 0x94e60000  lhu         $a2, 0x0($a3)
    ctx->pc = 0x1d01d0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d01d4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1d01d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d01d8: 0xc073a2c  jal         func_1CE8B0
    ctx->pc = 0x1D01D8u;
    SET_GPR_U32(ctx, 31, 0x1D01E0u);
    ctx->pc = 0x1D01DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01D8u;
            // 0x1d01dc: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE8B0u;
    if (runtime->hasFunction(0x1CE8B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CE8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01E0u; }
        if (ctx->pc != 0x1D01E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE8B0_0x1ce8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D01E0u; }
        if (ctx->pc != 0x1D01E0u) { return; }
    }
    ctx->pc = 0x1D01E0u;
label_1d01e0:
    // 0x1d01e0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d01e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d01e4: 0x2a030010  slti        $v1, $s0, 0x10
    ctx->pc = 0x1d01e4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d01e8: 0x1460ffe6  bnez        $v1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1D01E8u;
    {
        const bool branch_taken_0x1d01e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D01ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01E8u;
            // 0x1d01ec: 0x108840  sll         $s1, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d01e8) {
            ctx->pc = 0x1D0184u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0184;
        }
    }
    ctx->pc = 0x1D01F0u;
    // 0x1d01f0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d01f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d01f4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d01f4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d01f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d01f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d01fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D01FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D01FCu;
            // 0x1d0200: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0030u: goto label_1d0030;
            case 0x1D0048u: goto label_1d0048;
            case 0x1D006Cu: goto label_1d006c;
            case 0x1D0090u: goto label_1d0090;
            case 0x1D00D0u: goto label_1d00d0;
            case 0x1D00E0u: goto label_1d00e0;
            case 0x1D00ECu: goto label_1d00ec;
            case 0x1D010Cu: goto label_1d010c;
            case 0x1D0128u: goto label_1d0128;
            case 0x1D0134u: goto label_1d0134;
            case 0x1D014Cu: goto label_1d014c;
            case 0x1D0160u: goto label_1d0160;
            case 0x1D0170u: goto label_1d0170;
            case 0x1D0184u: goto label_1d0184;
            case 0x1D01A4u: goto label_1d01a4;
            case 0x1D01A8u: goto label_1d01a8;
            case 0x1D01C4u: goto label_1d01c4;
            case 0x1D01D0u: goto label_1d01d0;
            case 0x1D01E0u: goto label_1d01e0;
            case 0x1D0228u: goto label_1d0228;
            case 0x1D0230u: goto label_1d0230;
            case 0x1D024Cu: goto label_1d024c;
            case 0x1D026Cu: goto label_1d026c;
            case 0x1D028Cu: goto label_1d028c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0204u;
    // 0x1d0204: 0x0  nop
    ctx->pc = 0x1d0204u;
    // NOP
    // 0x1d0208: 0x0  nop
    ctx->pc = 0x1d0208u;
    // NOP
    // 0x1d020c: 0x0  nop
    ctx->pc = 0x1d020cu;
    // NOP
    // 0x1d0210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d0210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d0214: 0x24041400  addiu       $a0, $zero, 0x1400
    ctx->pc = 0x1d0214u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5120));
    // 0x1d0218: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d0218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d021c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d021cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0220: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0220u;
    SET_GPR_U32(ctx, 31, 0x1D0228u);
    ctx->pc = 0x1D0224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0220u;
            // 0x1d0224: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0228u; }
        if (ctx->pc != 0x1D0228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0228u; }
        if (ctx->pc != 0x1D0228u) { return; }
    }
    ctx->pc = 0x1D0228u;
label_1d0228:
    // 0x1d0228: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D0228u;
    SET_GPR_U32(ctx, 31, 0x1D0230u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0230u; }
        if (ctx->pc != 0x1D0230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0230u; }
        if (ctx->pc != 0x1D0230u) { return; }
    }
    ctx->pc = 0x1D0230u;
label_1d0230:
    // 0x1d0230: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0230u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0234: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1d0234u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1d0238: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1d0238u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d023c: 0x24638e80  addiu       $v1, $v1, -0x7180
    ctx->pc = 0x1d023cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938240));
    // 0x1d0240: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d0240u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0244: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1d0244u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1d0248: 0x648821  addu        $s1, $v1, $a0
    ctx->pc = 0x1d0248u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_1d024c:
    // 0x1d024c: 0x96250000  lhu         $a1, 0x0($s1)
    ctx->pc = 0x1d024cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d0250: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d0250u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d0254: 0x96240002  lhu         $a0, 0x2($s1)
    ctx->pc = 0x1d0254u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1d0258: 0x14a30004  bne         $a1, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0258u;
    {
        const bool branch_taken_0x1d0258 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D025Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0258u;
            // 0x1d025c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0258) {
            ctx->pc = 0x1D026Cu;
            goto label_1d026c;
        }
    }
    ctx->pc = 0x1D0260u;
    // 0x1d0260: 0x3083ffff  andi        $v1, $a0, 0xFFFF
    ctx->pc = 0x1d0260u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d0264: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D0264u;
    {
        const bool branch_taken_0x1d0264 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0264) {
            ctx->pc = 0x1D028Cu;
            goto label_1d028c;
        }
    }
    ctx->pc = 0x1D026Cu;
label_1d026c:
    // 0x1d026c: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d026cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d0270: 0x10a30006  beq         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D0270u;
    {
        const bool branch_taken_0x1d0270 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D0274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0270u;
            // 0x1d0274: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0270) {
            ctx->pc = 0x1D028Cu;
            goto label_1d028c;
        }
    }
    ctx->pc = 0x1D0278u;
    // 0x1d0278: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d0278u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d027c: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1d027cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d0280: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1d0280u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0284: 0xc073cc0  jal         func_1CF300
    ctx->pc = 0x1D0284u;
    SET_GPR_U32(ctx, 31, 0x1D028Cu);
    ctx->pc = 0x1D0288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0284u;
            // 0x1d0288: 0x2409ffff  addiu       $t1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF300u;
    if (runtime->hasFunction(0x1CF300u)) {
        auto targetFn = runtime->lookupFunction(0x1CF300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D028Cu; }
        if (ctx->pc != 0x1D028Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF300_0x1cf300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D028Cu; }
        if (ctx->pc != 0x1D028Cu) { return; }
    }
    ctx->pc = 0x1D028Cu;
label_1d028c:
    // 0x1d028c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d028cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d0290: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1d0290u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d0294: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1D0294u;
    {
        const bool branch_taken_0x1d0294 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0294) {
            ctx->pc = 0x1D024Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d024c;
        }
    }
    ctx->pc = 0x1D029Cu;
    // 0x1d029c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d029cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d02a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d02a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d02a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d02a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d02a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D02A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D02ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02A8u;
            // 0x1d02ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0030u: goto label_1d0030;
            case 0x1D0048u: goto label_1d0048;
            case 0x1D006Cu: goto label_1d006c;
            case 0x1D0090u: goto label_1d0090;
            case 0x1D00D0u: goto label_1d00d0;
            case 0x1D00E0u: goto label_1d00e0;
            case 0x1D00ECu: goto label_1d00ec;
            case 0x1D010Cu: goto label_1d010c;
            case 0x1D0128u: goto label_1d0128;
            case 0x1D0134u: goto label_1d0134;
            case 0x1D014Cu: goto label_1d014c;
            case 0x1D0160u: goto label_1d0160;
            case 0x1D0170u: goto label_1d0170;
            case 0x1D0184u: goto label_1d0184;
            case 0x1D01A4u: goto label_1d01a4;
            case 0x1D01A8u: goto label_1d01a8;
            case 0x1D01C4u: goto label_1d01c4;
            case 0x1D01D0u: goto label_1d01d0;
            case 0x1D01E0u: goto label_1d01e0;
            case 0x1D0228u: goto label_1d0228;
            case 0x1D0230u: goto label_1d0230;
            case 0x1D024Cu: goto label_1d024c;
            case 0x1D026Cu: goto label_1d026c;
            case 0x1D028Cu: goto label_1d028c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D02B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
