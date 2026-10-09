#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6FC0
// Address: 0x1f6fc0 - 0x1f7100
void sub_001F6FC0_0x1f6fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6FC0_0x1f6fc0");
#endif

    switch (ctx->pc) {
        case 0x1f7078u: goto label_1f7078;
        default: break;
    }

    ctx->pc = 0x1f6fc0u;

    // 0x1f6fc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6fc4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f6fc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6fc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6fcc: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x1f6fccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1f6fd0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6fd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6fd4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1f6fd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f6fd8: 0x10440040  beq         $v0, $a0, . + 4 + (0x40 << 2)
    ctx->pc = 0x1F6FD8u;
    {
        const bool branch_taken_0x1f6fd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1F6FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FD8u;
            // 0x1f6fdc: 0x24030064  addiu       $v1, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6fd8) {
            ctx->pc = 0x1F70DCu;
            goto label_1f70dc;
        }
    }
    ctx->pc = 0x1F6FE0u;
    // 0x1f6fe0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6fe0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6fe4: 0x1043001b  beq         $v0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1F6FE4u;
    {
        const bool branch_taken_0x1f6fe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f6fe4) {
            ctx->pc = 0x1F7054u;
            goto label_1f7054;
        }
    }
    ctx->pc = 0x1F6FECu;
    // 0x1f6fec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6FECu;
    {
        const bool branch_taken_0x1f6fec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6fec) {
            ctx->pc = 0x1F6FFCu;
            goto label_1f6ffc;
        }
    }
    ctx->pc = 0x1F6FF4u;
    // 0x1f6ff4: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1F6FF4u;
    {
        const bool branch_taken_0x1f6ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FF4u;
            // 0x1f6ff8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ff4) {
            ctx->pc = 0x1F70F0u;
            goto label_1f70f0;
        }
    }
    ctx->pc = 0x1F6FFCu;
label_1f6ffc:
    // 0x1f6ffc: 0x24020062  addiu       $v0, $zero, 0x62
    ctx->pc = 0x1f6ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1f7000: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f7000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f7004: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f7004u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f7008: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f7008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f700c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F700Cu;
    {
        const bool branch_taken_0x1f700c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f700c) {
            ctx->pc = 0x1F703Cu;
            goto label_1f703c;
        }
    }
    ctx->pc = 0x1F7014u;
    // 0x1f7014: 0x10440005  beq         $v0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7014u;
    {
        const bool branch_taken_0x1f7014 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1f7014) {
            ctx->pc = 0x1F702Cu;
            goto label_1f702c;
        }
    }
    ctx->pc = 0x1F701Cu;
    // 0x1f701c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F701Cu;
    {
        const bool branch_taken_0x1f701c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f701c) {
            ctx->pc = 0x1F702Cu;
            goto label_1f702c;
        }
    }
    ctx->pc = 0x1F7024u;
    // 0x1f7024: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F7024u;
    {
        const bool branch_taken_0x1f7024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7024u;
            // 0x1f7028: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7024) {
            ctx->pc = 0x1F704Cu;
            goto label_1f704c;
        }
    }
    ctx->pc = 0x1F702Cu;
label_1f702c:
    // 0x1f702c: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f702cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f7030: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f7030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f7034: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F7034u;
    {
        const bool branch_taken_0x1f7034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7034u;
            // 0x1f7038: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7034) {
            ctx->pc = 0x1F7048u;
            goto label_1f7048;
        }
    }
    ctx->pc = 0x1F703Cu;
label_1f703c:
    // 0x1f703c: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f703cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f7040: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f7040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f7044: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f7044u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f7048:
    // 0x1f7048: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f7048u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
label_1f704c:
    // 0x1f704c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1F704Cu;
    {
        const bool branch_taken_0x1f704c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F704Cu;
            // 0x1f7050: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f704c) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F7054u;
label_1f7054:
    // 0x1f7054: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1f7054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1f7058: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1f7058u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1f705c: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1f705cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1f7060: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x1f7060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1f7064: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f7064u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f7068: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x1f7068u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1f706c: 0x24c6cc58  addiu       $a2, $a2, -0x33A8
    ctx->pc = 0x1f706cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294954072));
    // 0x1f7070: 0xc0724bc  jal         func_1C92F0
    ctx->pc = 0x1F7070u;
    SET_GPR_U32(ctx, 31, 0x1F7078u);
    ctx->pc = 0x1F7074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7070u;
            // 0x1f7074: 0x24e7cc60  addiu       $a3, $a3, -0x33A0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294954080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C92F0u;
    if (runtime->hasFunction(0x1C92F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C92F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7078u; }
        if (ctx->pc != 0x1F7078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C92F0_0x1c92f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7078u; }
        if (ctx->pc != 0x1F7078u) { return; }
    }
    ctx->pc = 0x1F7078u;
label_1f7078:
    // 0x1f7078: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f7078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f707c: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1F707Cu;
    {
        const bool branch_taken_0x1f707c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F7080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F707Cu;
            // 0x1f7080: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f707c) {
            ctx->pc = 0x1F70B0u;
            goto label_1f70b0;
        }
    }
    ctx->pc = 0x1F7084u;
    // 0x1f7084: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f7084u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f7088: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7088u;
    {
        const bool branch_taken_0x1f7088 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f7088) {
            ctx->pc = 0x1F70A0u;
            goto label_1f70a0;
        }
    }
    ctx->pc = 0x1F7090u;
    // 0x1f7090: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1F7090u;
    {
        const bool branch_taken_0x1f7090 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f7090) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F7098u;
    // 0x1f7098: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1F7098u;
    {
        const bool branch_taken_0x1f7098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f7098) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70A0u;
label_1f70a0:
    // 0x1f70a0: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f70a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f70a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f70a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f70a8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F70A8u;
    {
        const bool branch_taken_0x1f70a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F70ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70A8u;
            // 0x1f70ac: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f70a8) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70B0u;
label_1f70b0:
    // 0x1f70b0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f70b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f70b4: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f70b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f70b8: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f70b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f70bc: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f70bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c0: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f70c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c4: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f70c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c8: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f70c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70cc: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f70ccu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70d0: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f70d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70d4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F70D4u;
    {
        const bool branch_taken_0x1f70d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F70D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70D4u;
            // 0x1f70d8: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f70d4) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70DCu;
label_1f70dc:
    // 0x1f70dc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1f70dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f70e0: 0xae030090  sw          $v1, 0x90($s0)
    ctx->pc = 0x1f70e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 3));
    // 0x1f70e4: 0xae020088  sw          $v0, 0x88($s0)
    ctx->pc = 0x1f70e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 2));
    // 0x1f70e8: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x1f70e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
label_1f70ec:
    // 0x1f70ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f70ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f70f0:
    // 0x1f70f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f70f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f70f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f70f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f70f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F70F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F70FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70F8u;
            // 0x1f70fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F7100u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
