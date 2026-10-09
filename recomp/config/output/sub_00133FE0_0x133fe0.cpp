#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133FE0
// Address: 0x133fe0 - 0x1343b8
void sub_00133FE0_0x133fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133FE0_0x133fe0");
#endif

    switch (ctx->pc) {
        case 0x134034u: goto label_134034;
        case 0x13405cu: goto label_13405c;
        case 0x134074u: goto label_134074;
        case 0x134080u: goto label_134080;
        case 0x134094u: goto label_134094;
        case 0x1340b4u: goto label_1340b4;
        case 0x1340c4u: goto label_1340c4;
        case 0x1340ccu: goto label_1340cc;
        case 0x1340e0u: goto label_1340e0;
        case 0x1340ecu: goto label_1340ec;
        case 0x134150u: goto label_134150;
        case 0x13417cu: goto label_13417c;
        case 0x1341a8u: goto label_1341a8;
        case 0x1341e8u: goto label_1341e8;
        case 0x1341fcu: goto label_1341fc;
        case 0x134204u: goto label_134204;
        case 0x13420cu: goto label_13420c;
        case 0x13421cu: goto label_13421c;
        case 0x134228u: goto label_134228;
        case 0x134234u: goto label_134234;
        case 0x134248u: goto label_134248;
        case 0x134264u: goto label_134264;
        case 0x13426cu: goto label_13426c;
        case 0x134278u: goto label_134278;
        case 0x134284u: goto label_134284;
        case 0x134290u: goto label_134290;
        case 0x1342a4u: goto label_1342a4;
        case 0x1342acu: goto label_1342ac;
        case 0x1342b8u: goto label_1342b8;
        case 0x1342c4u: goto label_1342c4;
        case 0x1342d0u: goto label_1342d0;
        case 0x1342dcu: goto label_1342dc;
        case 0x1342e8u: goto label_1342e8;
        case 0x1342f4u: goto label_1342f4;
        case 0x134300u: goto label_134300;
        case 0x134308u: goto label_134308;
        case 0x134318u: goto label_134318;
        case 0x134328u: goto label_134328;
        case 0x134344u: goto label_134344;
        case 0x13434cu: goto label_13434c;
        case 0x134360u: goto label_134360;
        case 0x13436cu: goto label_13436c;
        case 0x13437cu: goto label_13437c;
        case 0x134388u: goto label_134388;
        case 0x134394u: goto label_134394;
        default: break;
    }

    ctx->pc = 0x133fe0u;

    // 0x133fe0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x133fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x133fe4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x133fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x133fe8: 0x24100800  addiu       $s0, $zero, 0x800
    ctx->pc = 0x133fe8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x133fec: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x133fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x133ff0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x133ff0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ff4: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x133ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x133ff8: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x133ff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x133ffc: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x133ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x134000: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x134000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x134004: 0xafa00020  sw          $zero, 0x20($sp)
    ctx->pc = 0x134004u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x134008: 0x8e330004  lw          $s3, 0x4($s1)
    ctx->pc = 0x134008u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13400c: 0x92220002  lbu         $v0, 0x2($s1)
    ctx->pc = 0x13400cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x134010: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x134010u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x134014: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x134014u;
    {
        const bool branch_taken_0x134014 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134014u;
            // 0x134018: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134014) {
            ctx->pc = 0x134078u;
            goto label_134078;
        }
    }
    ctx->pc = 0x13401Cu;
    // 0x13401c: 0x822300ac  lb          $v1, 0xAC($s1)
    ctx->pc = 0x13401cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 172)));
    // 0x134020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x134020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x134024: 0x14620014  bne         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x134024u;
    {
        const bool branch_taken_0x134024 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x134024) {
            ctx->pc = 0x134078u;
            goto label_134078;
        }
    }
    ctx->pc = 0x13402Cu;
    // 0x13402c: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x13402Cu;
    SET_GPR_U32(ctx, 31, 0x134034u);
    ctx->pc = 0x134030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13402Cu;
            // 0x134030: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134034u; }
        if (ctx->pc != 0x134034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134034u; }
        if (ctx->pc != 0x134034u) { return; }
    }
    ctx->pc = 0x134034u;
label_134034:
    // 0x134034: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x134034u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x134038: 0x504300d8  beql        $v0, $v1, . + 4 + (0xD8 << 2)
    ctx->pc = 0x134038u;
    {
        const bool branch_taken_0x134038 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x134038) {
            ctx->pc = 0x13403Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134038u;
            // 0x13403c: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13439Cu;
            goto label_13439c;
        }
    }
    ctx->pc = 0x134040u;
    // 0x134040: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x134040u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x134044: 0x50800006  beql        $a0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x134044u;
    {
        const bool branch_taken_0x134044 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x134044) {
            ctx->pc = 0x134048u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134044u;
            // 0x134048: 0x8e2500b4  lw          $a1, 0xB4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 180)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134060u;
            goto label_134060;
        }
    }
    ctx->pc = 0x13404Cu;
    // 0x13404c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13404cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x134050: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x134050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x134054: 0x40f809  jalr        $v0
    ctx->pc = 0x134054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13405Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x13405Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134034u: goto label_134034;
            case 0x13405Cu: goto label_13405c;
            case 0x134060u: goto label_134060;
            case 0x134074u: goto label_134074;
            case 0x134078u: goto label_134078;
            case 0x134080u: goto label_134080;
            case 0x134094u: goto label_134094;
            case 0x1340B4u: goto label_1340b4;
            case 0x1340C4u: goto label_1340c4;
            case 0x1340CCu: goto label_1340cc;
            case 0x1340D8u: goto label_1340d8;
            case 0x1340E0u: goto label_1340e0;
            case 0x1340ECu: goto label_1340ec;
            case 0x134108u: goto label_134108;
            case 0x134120u: goto label_134120;
            case 0x13412Cu: goto label_13412c;
            case 0x134148u: goto label_134148;
            case 0x134150u: goto label_134150;
            case 0x134168u: goto label_134168;
            case 0x13417Cu: goto label_13417c;
            case 0x1341A0u: goto label_1341a0;
            case 0x1341A8u: goto label_1341a8;
            case 0x1341B0u: goto label_1341b0;
            case 0x1341E8u: goto label_1341e8;
            case 0x1341FCu: goto label_1341fc;
            case 0x134204u: goto label_134204;
            case 0x13420Cu: goto label_13420c;
            case 0x13421Cu: goto label_13421c;
            case 0x134228u: goto label_134228;
            case 0x134234u: goto label_134234;
            case 0x134248u: goto label_134248;
            case 0x134250u: goto label_134250;
            case 0x134264u: goto label_134264;
            case 0x13426Cu: goto label_13426c;
            case 0x134278u: goto label_134278;
            case 0x134284u: goto label_134284;
            case 0x134290u: goto label_134290;
            case 0x1342A4u: goto label_1342a4;
            case 0x1342ACu: goto label_1342ac;
            case 0x1342B8u: goto label_1342b8;
            case 0x1342C4u: goto label_1342c4;
            case 0x1342D0u: goto label_1342d0;
            case 0x1342DCu: goto label_1342dc;
            case 0x1342E8u: goto label_1342e8;
            case 0x1342F4u: goto label_1342f4;
            case 0x134300u: goto label_134300;
            case 0x134308u: goto label_134308;
            case 0x134318u: goto label_134318;
            case 0x134328u: goto label_134328;
            case 0x13433Cu: goto label_13433c;
            case 0x134344u: goto label_134344;
            case 0x13434Cu: goto label_13434c;
            case 0x134360u: goto label_134360;
            case 0x134364u: goto label_134364;
            case 0x13436Cu: goto label_13436c;
            case 0x13437Cu: goto label_13437c;
            case 0x134388u: goto label_134388;
            case 0x13438Cu: goto label_13438c;
            case 0x134394u: goto label_134394;
            case 0x13439Cu: goto label_13439c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13405Cu; }
            if (ctx->pc != 0x13405Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13405Cu;
label_13405c:
    // 0x13405c: 0x8e2500b4  lw          $a1, 0xB4($s1)
    ctx->pc = 0x13405cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 180)));
label_134060:
    // 0x134060: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x134060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134064: 0x8e2600b8  lw          $a2, 0xB8($s1)
    ctx->pc = 0x134064u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 184)));
    // 0x134068: 0x8e2700bc  lw          $a3, 0xBC($s1)
    ctx->pc = 0x134068u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 188)));
    // 0x13406c: 0xc04c714  jal         func_131C50
    ctx->pc = 0x13406Cu;
    SET_GPR_U32(ctx, 31, 0x134074u);
    ctx->pc = 0x134070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13406Cu;
            // 0x134070: 0x8e2800c0  lw          $t0, 0xC0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 192)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131C50u;
    if (runtime->hasFunction(0x131C50u)) {
        auto targetFn = runtime->lookupFunction(0x131C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134074u; }
        if (ctx->pc != 0x134074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131C50_0x131c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134074u; }
        if (ctx->pc != 0x134074u) { return; }
    }
    ctx->pc = 0x134074u;
label_134074:
    // 0x134074: 0xa22000ac  sb          $zero, 0xAC($s1)
    ctx->pc = 0x134074u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 172), (uint8_t)GPR_U32(ctx, 0));
label_134078:
    // 0x134078: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x134078u;
    SET_GPR_U32(ctx, 31, 0x134080u);
    ctx->pc = 0x13407Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134078u;
            // 0x13407c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134080u; }
        if (ctx->pc != 0x134080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134080u; }
        if (ctx->pc != 0x134080u) { return; }
    }
    ctx->pc = 0x134080u;
label_134080:
    // 0x134080: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x134080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x134084: 0x544300c5  bnel        $v0, $v1, . + 4 + (0xC5 << 2)
    ctx->pc = 0x134084u;
    {
        const bool branch_taken_0x134084 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x134084) {
            ctx->pc = 0x134088u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134084u;
            // 0x134088: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13439Cu;
            goto label_13439c;
        }
    }
    ctx->pc = 0x13408Cu;
    // 0x13408c: 0xc04b5ea  jal         func_12D7A8
    ctx->pc = 0x13408Cu;
    SET_GPR_U32(ctx, 31, 0x134094u);
    ctx->pc = 0x134090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13408Cu;
            // 0x134090: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7A8u;
    if (runtime->hasFunction(0x12D7A8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134094u; }
        if (ctx->pc != 0x134094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134094u; }
        if (ctx->pc != 0x134094u) { return; }
    }
    ctx->pc = 0x134094u;
label_134094:
    // 0x134094: 0x82250003  lb          $a1, 0x3($s1)
    ctx->pc = 0x134094u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x134098: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x134098u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13409c: 0xb2102a  slt         $v0, $a1, $s2
    ctx->pc = 0x13409cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1340a0: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1340A0u;
    {
        const bool branch_taken_0x1340a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1340A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1340A0u;
            // 0x1340a4: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1340a0) {
            ctx->pc = 0x1340D8u;
            goto label_1340d8;
        }
    }
    ctx->pc = 0x1340A8u;
    // 0x1340a8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1340a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1340ac: 0xc04a0a8  jal         func_1282A0
    ctx->pc = 0x1340ACu;
    SET_GPR_U32(ctx, 31, 0x1340B4u);
    ctx->pc = 0x1340B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1340ACu;
            // 0x1340b0: 0x24070010  addiu       $a3, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1282A0u;
    if (runtime->hasFunction(0x1282A0u)) {
        auto targetFn = runtime->lookupFunction(0x1282A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340B4u; }
        if (ctx->pc != 0x1340B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001282A0_0x1282a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340B4u; }
        if (ctx->pc != 0x1340B4u) { return; }
    }
    ctx->pc = 0x1340B4u;
label_1340b4:
    // 0x1340b4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1340b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1340b8: 0x2484b6f0  addiu       $a0, $a0, -0x4910
    ctx->pc = 0x1340b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948592));
    // 0x1340bc: 0xc04a04a  jal         func_128128
    ctx->pc = 0x1340BCu;
    SET_GPR_U32(ctx, 31, 0x1340C4u);
    ctx->pc = 0x1340C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1340BCu;
            // 0x1340c0: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340C4u; }
        if (ctx->pc != 0x1340C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340C4u; }
        if (ctx->pc != 0x1340C4u) { return; }
    }
    ctx->pc = 0x1340C4u;
label_1340c4:
    // 0x1340c4: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1340C4u;
    SET_GPR_U32(ctx, 31, 0x1340CCu);
    ctx->pc = 0x1340C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1340C4u;
            // 0x1340c8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340CCu; }
        if (ctx->pc != 0x1340CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340CCu; }
        if (ctx->pc != 0x1340CCu) { return; }
    }
    ctx->pc = 0x1340CCu;
label_1340cc:
    // 0x1340cc: 0x100000b3  b           . + 4 + (0xB3 << 2)
    ctx->pc = 0x1340CCu;
    {
        const bool branch_taken_0x1340cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1340D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1340CCu;
            // 0x1340d0: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1340cc) {
            ctx->pc = 0x13439Cu;
            goto label_13439c;
        }
    }
    ctx->pc = 0x1340D4u;
    // 0x1340d4: 0x0  nop
    ctx->pc = 0x1340d4u;
    // NOP
label_1340d8:
    // 0x1340d8: 0xc04b5e4  jal         func_12D790
    ctx->pc = 0x1340D8u;
    SET_GPR_U32(ctx, 31, 0x1340E0u);
    ctx->pc = 0x1340DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1340D8u;
            // 0x1340dc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D790u;
    if (runtime->hasFunction(0x12D790u)) {
        auto targetFn = runtime->lookupFunction(0x12D790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340E0u; }
        if (ctx->pc != 0x1340E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D790_0x12d790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340E0u; }
        if (ctx->pc != 0x1340E0u) { return; }
    }
    ctx->pc = 0x1340E0u;
label_1340e0:
    // 0x1340e0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1340e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1340e4: 0xc04b60e  jal         func_12D838
    ctx->pc = 0x1340E4u;
    SET_GPR_U32(ctx, 31, 0x1340ECu);
    ctx->pc = 0x1340E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1340E4u;
            // 0x1340e8: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D838u;
    if (runtime->hasFunction(0x12D838u)) {
        auto targetFn = runtime->lookupFunction(0x12D838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340ECu; }
        if (ctx->pc != 0x1340ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D838_0x12d838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1340ECu; }
        if (ctx->pc != 0x1340ECu) { return; }
    }
    ctx->pc = 0x1340ECu;
label_1340ec:
    // 0x1340ec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1340ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1340f0: 0x5a40000b  blezl       $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x1340F0u;
    {
        const bool branch_taken_0x1340f0 = (GPR_S64(ctx, 18) <= 0);
        if (branch_taken_0x1340f0) {
            ctx->pc = 0x1340F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1340F0u;
            // 0x1340f4: 0x8e230038  lw          $v1, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134120u;
            goto label_134120;
        }
    }
    ctx->pc = 0x1340F8u;
    // 0x1340f8: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x1340f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x1340fc: 0x282001a  div         $zero, $s4, $v0
    ctx->pc = 0x1340fcu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 20);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x134100: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x134100u;
    {
        const bool branch_taken_0x134100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134100) {
            ctx->pc = 0x134104u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134100u;
            // 0x134104: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x134108u;
            goto label_134108;
        }
    }
    ctx->pc = 0x134108u;
label_134108:
    // 0x134108: 0x2012  mflo        $a0
    ctx->pc = 0x134108u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x13410c: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x13410cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x134110: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x134110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x134114: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x134114u;
    {
        const bool branch_taken_0x134114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134114u;
            // 0x134118: 0xae230048  sw          $v1, 0x48($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134114) {
            ctx->pc = 0x134148u;
            goto label_134148;
        }
    }
    ctx->pc = 0x13411Cu;
    // 0x13411c: 0x0  nop
    ctx->pc = 0x13411cu;
    // NOP
label_134120:
    // 0x134120: 0x283001a  div         $zero, $s4, $v1
    ctx->pc = 0x134120u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 20);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x134124: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x134124u;
    {
        const bool branch_taken_0x134124 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x134124) {
            ctx->pc = 0x134128u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134124u;
            // 0x134128: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13412Cu;
            goto label_13412c;
        }
    }
    ctx->pc = 0x13412Cu;
label_13412c:
    // 0x13412c: 0x2012  mflo        $a0
    ctx->pc = 0x13412cu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x134130: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x134130u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x134134: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x134134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x134138: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x134138u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x13413c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13413cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x134140: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x134140u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x134144: 0xae220048  sw          $v0, 0x48($s1)
    ctx->pc = 0x134144u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 2));
label_134148:
    // 0x134148: 0xc04b5f6  jal         func_12D7D8
    ctx->pc = 0x134148u;
    SET_GPR_U32(ctx, 31, 0x134150u);
    ctx->pc = 0x13414Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134148u;
            // 0x13414c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7D8u;
    if (runtime->hasFunction(0x12D7D8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134150u; }
        if (ctx->pc != 0x134150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7D8_0x12d7d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134150u; }
        if (ctx->pc != 0x134150u) { return; }
    }
    ctx->pc = 0x134150u;
label_134150:
    // 0x134150: 0x8e250048  lw          $a1, 0x48($s1)
    ctx->pc = 0x134150u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x134154: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x134154u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x134158: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13415c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13415cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x134160: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x134160u;
    {
        const bool branch_taken_0x134160 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134160) {
            ctx->pc = 0x134164u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134160u;
            // 0x134164: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x134168u;
            goto label_134168;
        }
    }
    ctx->pc = 0x134168u;
label_134168:
    // 0x134168: 0xa2001a  div         $zero, $a1, $v0
    ctx->pc = 0x134168u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13416c: 0x2812  mflo        $a1
    ctx->pc = 0x13416cu;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x134170: 0xa22818  mult        $a1, $a1, $v0
    ctx->pc = 0x134170u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x134174: 0xc04b304  jal         func_12CC10
    ctx->pc = 0x134174u;
    SET_GPR_U32(ctx, 31, 0x13417Cu);
    ctx->pc = 0x134178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134174u;
            // 0x134178: 0xae250048  sw          $a1, 0x48($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC10u;
    if (runtime->hasFunction(0x12CC10u)) {
        auto targetFn = runtime->lookupFunction(0x12CC10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13417Cu; }
        if (ctx->pc != 0x13417Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC10_0x12cc10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13417Cu; }
        if (ctx->pc != 0x13417Cu) { return; }
    }
    ctx->pc = 0x13417Cu;
label_13417c:
    // 0x13417c: 0x5a400034  blezl       $s2, . + 4 + (0x34 << 2)
    ctx->pc = 0x13417Cu;
    {
        const bool branch_taken_0x13417c = (GPR_S64(ctx, 18) <= 0);
        if (branch_taken_0x13417c) {
            ctx->pc = 0x134180u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13417Cu;
            // 0x134180: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134250u;
            goto label_134250;
        }
    }
    ctx->pc = 0x134184u;
    // 0x134184: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x134184u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x134188: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x134188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13418c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13418Cu;
    {
        const bool branch_taken_0x13418c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13418c) {
            ctx->pc = 0x1341A0u;
            goto label_1341a0;
        }
    }
    ctx->pc = 0x134194u;
    // 0x134194: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x134194u;
    {
        const bool branch_taken_0x134194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134194u;
            // 0x134198: 0xae200050  sw          $zero, 0x50($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 80), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134194) {
            ctx->pc = 0x1341FCu;
            goto label_1341fc;
        }
    }
    ctx->pc = 0x13419Cu;
    // 0x13419c: 0x0  nop
    ctx->pc = 0x13419cu;
    // NOP
label_1341a0:
    // 0x1341a0: 0xc04b632  jal         func_12D8C8
    ctx->pc = 0x1341A0u;
    SET_GPR_U32(ctx, 31, 0x1341A8u);
    ctx->pc = 0x1341A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1341A0u;
            // 0x1341a4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8C8u;
    if (runtime->hasFunction(0x12D8C8u)) {
        auto targetFn = runtime->lookupFunction(0x12D8C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341A8u; }
        if (ctx->pc != 0x1341A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8C8_0x12d8c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341A8u; }
        if (ctx->pc != 0x1341A8u) { return; }
    }
    ctx->pc = 0x1341A8u;
label_1341a8:
    // 0x1341a8: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1341A8u;
    {
        const bool branch_taken_0x1341a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1341a8) {
            ctx->pc = 0x1341ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1341A8u;
            // 0x1341ac: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1341B0u;
            goto label_1341b0;
        }
    }
    ctx->pc = 0x1341B0u;
label_1341b0:
    // 0x1341b0: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x1341b0u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1341b4: 0x244207ff  addiu       $v0, $v0, 0x7FF
    ctx->pc = 0x1341b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x1341b8: 0x1810  mfhi        $v1
    ctx->pc = 0x1341b8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1341bc: 0x50001a  div         $zero, $v0, $s0
    ctx->pc = 0x1341bcu;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1341c0: 0x2031823  subu        $v1, $s0, $v1
    ctx->pc = 0x1341c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1341c4: 0xae230050  sw          $v1, 0x50($s1)
    ctx->pc = 0x1341c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 80), GPR_U32(ctx, 3));
    // 0x1341c8: 0x1012  mflo        $v0
    ctx->pc = 0x1341c8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1341cc: 0x70001a  div         $zero, $v1, $s0
    ctx->pc = 0x1341ccu;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1341d0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1341d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1341d4: 0x2010  mfhi        $a0
    ctx->pc = 0x1341d4u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x1341d8: 0xae240050  sw          $a0, 0x50($s1)
    ctx->pc = 0x1341d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 80), GPR_U32(ctx, 4));
    // 0x1341dc: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1341dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1341e0: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x1341E0u;
    SET_GPR_U32(ctx, 31, 0x1341E8u);
    ctx->pc = 0x1341E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1341E0u;
            // 0x1341e4: 0xae22008c  sw          $v0, 0x8C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341E8u; }
        if (ctx->pc != 0x1341E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341E8u; }
        if (ctx->pc != 0x1341E8u) { return; }
    }
    ctx->pc = 0x1341E8u;
label_1341e8:
    // 0x1341e8: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x1341e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x1341ec: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1341ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1341f0: 0x24a53ab8  addiu       $a1, $a1, 0x3AB8
    ctx->pc = 0x1341f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15032));
    // 0x1341f4: 0xc04c1e6  jal         func_130798
    ctx->pc = 0x1341F4u;
    SET_GPR_U32(ctx, 31, 0x1341FCu);
    ctx->pc = 0x1341F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1341F4u;
            // 0x1341f8: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130798u;
    if (runtime->hasFunction(0x130798u)) {
        auto targetFn = runtime->lookupFunction(0x130798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341FCu; }
        if (ctx->pc != 0x1341FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130798_0x130798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1341FCu; }
        if (ctx->pc != 0x1341FCu) { return; }
    }
    ctx->pc = 0x1341FCu;
label_1341fc:
    // 0x1341fc: 0xc04b62c  jal         func_12D8B0
    ctx->pc = 0x1341FCu;
    SET_GPR_U32(ctx, 31, 0x134204u);
    ctx->pc = 0x134200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1341FCu;
            // 0x134200: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8B0u;
    if (runtime->hasFunction(0x12D8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12D8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134204u; }
        if (ctx->pc != 0x134204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8B0_0x12d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134204u; }
        if (ctx->pc != 0x134204u) { return; }
    }
    ctx->pc = 0x134204u;
label_134204:
    // 0x134204: 0xc04b61a  jal         func_12D868
    ctx->pc = 0x134204u;
    SET_GPR_U32(ctx, 31, 0x13420Cu);
    ctx->pc = 0x134208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134204u;
            // 0x134208: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D868u;
    if (runtime->hasFunction(0x12D868u)) {
        auto targetFn = runtime->lookupFunction(0x12D868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13420Cu; }
        if (ctx->pc != 0x13420Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D868_0x12d868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13420Cu; }
        if (ctx->pc != 0x13420Cu) { return; }
    }
    ctx->pc = 0x13420Cu;
label_13420c:
    // 0x13420c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13420cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134210: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x134210u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x134214: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x134214u;
    SET_GPR_U32(ctx, 31, 0x13421Cu);
    ctx->pc = 0x134218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134214u;
            // 0x134218: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13421Cu; }
        if (ctx->pc != 0x13421Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13421Cu; }
        if (ctx->pc != 0x13421Cu) { return; }
    }
    ctx->pc = 0x13421Cu;
label_13421c:
    // 0x13421c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13421cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134220: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x134220u;
    SET_GPR_U32(ctx, 31, 0x134228u);
    ctx->pc = 0x134224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134220u;
            // 0x134224: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134228u; }
        if (ctx->pc != 0x134228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134228u; }
        if (ctx->pc != 0x134228u) { return; }
    }
    ctx->pc = 0x134228u;
label_134228:
    // 0x134228: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134228u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13422c: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x13422Cu;
    SET_GPR_U32(ctx, 31, 0x134234u);
    ctx->pc = 0x134230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13422Cu;
            // 0x134230: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134234u; }
        if (ctx->pc != 0x134234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134234u; }
        if (ctx->pc != 0x134234u) { return; }
    }
    ctx->pc = 0x134234u;
label_134234:
    // 0x134234: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x134234u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x134238: 0x24a53870  addiu       $a1, $a1, 0x3870
    ctx->pc = 0x134238u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14448));
    // 0x13423c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13423cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134240: 0xc04b5ce  jal         func_12D738
    ctx->pc = 0x134240u;
    SET_GPR_U32(ctx, 31, 0x134248u);
    ctx->pc = 0x134244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134240u;
            // 0x134244: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D738u;
    if (runtime->hasFunction(0x12D738u)) {
        auto targetFn = runtime->lookupFunction(0x12D738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134248u; }
        if (ctx->pc != 0x134248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D738_0x12d738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134248u; }
        if (ctx->pc != 0x134248u) { return; }
    }
    ctx->pc = 0x134248u;
label_134248:
    // 0x134248: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x134248u;
    {
        const bool branch_taken_0x134248 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x134248) {
            ctx->pc = 0x1342A4u;
            goto label_1342a4;
        }
    }
    ctx->pc = 0x134250u;
label_134250:
    // 0x134250: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x134250u;
    {
        const bool branch_taken_0x134250 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x134250) {
            ctx->pc = 0x134264u;
            goto label_134264;
        }
    }
    ctx->pc = 0x134258u;
    // 0x134258: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x134258u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
    // 0x13425c: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x13425Cu;
    SET_GPR_U32(ctx, 31, 0x134264u);
    ctx->pc = 0x134260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13425Cu;
            // 0x134260: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134264u; }
        if (ctx->pc != 0x134264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134264u; }
        if (ctx->pc != 0x134264u) { return; }
    }
    ctx->pc = 0x134264u;
label_134264:
    // 0x134264: 0xc04b602  jal         func_12D808
    ctx->pc = 0x134264u;
    SET_GPR_U32(ctx, 31, 0x13426Cu);
    ctx->pc = 0x134268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134264u;
            // 0x134268: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13426Cu; }
        if (ctx->pc != 0x13426Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13426Cu; }
        if (ctx->pc != 0x13426Cu) { return; }
    }
    ctx->pc = 0x13426Cu;
label_13426c:
    // 0x13426c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13426cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134270: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x134270u;
    SET_GPR_U32(ctx, 31, 0x134278u);
    ctx->pc = 0x134274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134270u;
            // 0x134274: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134278u; }
        if (ctx->pc != 0x134278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134278u; }
        if (ctx->pc != 0x134278u) { return; }
    }
    ctx->pc = 0x134278u;
label_134278:
    // 0x134278: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134278u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13427c: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x13427Cu;
    SET_GPR_U32(ctx, 31, 0x134284u);
    ctx->pc = 0x134280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13427Cu;
            // 0x134280: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134284u; }
        if (ctx->pc != 0x134284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134284u; }
        if (ctx->pc != 0x134284u) { return; }
    }
    ctx->pc = 0x134284u;
label_134284:
    // 0x134284: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134288: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x134288u;
    SET_GPR_U32(ctx, 31, 0x134290u);
    ctx->pc = 0x13428Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134288u;
            // 0x13428c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134290u; }
        if (ctx->pc != 0x134290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134290u; }
        if (ctx->pc != 0x134290u) { return; }
    }
    ctx->pc = 0x134290u;
label_134290:
    // 0x134290: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x134290u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x134294: 0x24a53d10  addiu       $a1, $a1, 0x3D10
    ctx->pc = 0x134294u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15632));
    // 0x134298: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13429c: 0xc04b5ce  jal         func_12D738
    ctx->pc = 0x13429Cu;
    SET_GPR_U32(ctx, 31, 0x1342A4u);
    ctx->pc = 0x1342A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13429Cu;
            // 0x1342a0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D738u;
    if (runtime->hasFunction(0x12D738u)) {
        auto targetFn = runtime->lookupFunction(0x12D738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342A4u; }
        if (ctx->pc != 0x1342A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D738_0x12d738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342A4u; }
        if (ctx->pc != 0x1342A4u) { return; }
    }
    ctx->pc = 0x1342A4u;
label_1342a4:
    // 0x1342a4: 0xc04b5e4  jal         func_12D790
    ctx->pc = 0x1342A4u;
    SET_GPR_U32(ctx, 31, 0x1342ACu);
    ctx->pc = 0x1342A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342A4u;
            // 0x1342a8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D790u;
    if (runtime->hasFunction(0x12D790u)) {
        auto targetFn = runtime->lookupFunction(0x12D790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342ACu; }
        if (ctx->pc != 0x1342ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D790_0x12d790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342ACu; }
        if (ctx->pc != 0x1342ACu) { return; }
    }
    ctx->pc = 0x1342ACu;
label_1342ac:
    // 0x1342ac: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1342acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1342b0: 0xc04b5ea  jal         func_12D7A8
    ctx->pc = 0x1342B0u;
    SET_GPR_U32(ctx, 31, 0x1342B8u);
    ctx->pc = 0x1342B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342B0u;
            // 0x1342b4: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7A8u;
    if (runtime->hasFunction(0x12D7A8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342B8u; }
        if (ctx->pc != 0x1342B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342B8u; }
        if (ctx->pc != 0x1342B8u) { return; }
    }
    ctx->pc = 0x1342B8u;
label_1342b8:
    // 0x1342b8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1342b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1342bc: 0xc04b602  jal         func_12D808
    ctx->pc = 0x1342BCu;
    SET_GPR_U32(ctx, 31, 0x1342C4u);
    ctx->pc = 0x1342C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342BCu;
            // 0x1342c0: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342C4u; }
        if (ctx->pc != 0x1342C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342C4u; }
        if (ctx->pc != 0x1342C4u) { return; }
    }
    ctx->pc = 0x1342C4u;
label_1342c4:
    // 0x1342c4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1342c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1342c8: 0xc04b5f0  jal         func_12D7C0
    ctx->pc = 0x1342C8u;
    SET_GPR_U32(ctx, 31, 0x1342D0u);
    ctx->pc = 0x1342CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342C8u;
            // 0x1342cc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7C0u;
    if (runtime->hasFunction(0x12D7C0u)) {
        auto targetFn = runtime->lookupFunction(0x12D7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342D0u; }
        if (ctx->pc != 0x1342D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7C0_0x12d7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342D0u; }
        if (ctx->pc != 0x1342D0u) { return; }
    }
    ctx->pc = 0x1342D0u;
label_1342d0:
    // 0x1342d0: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1342d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1342d4: 0xc04b20c  jal         func_12C830
    ctx->pc = 0x1342D4u;
    SET_GPR_U32(ctx, 31, 0x1342DCu);
    ctx->pc = 0x1342D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342D4u;
            // 0x1342d8: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C830u;
    if (runtime->hasFunction(0x12C830u)) {
        auto targetFn = runtime->lookupFunction(0x12C830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342DCu; }
        if (ctx->pc != 0x1342DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C830_0x12c830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342DCu; }
        if (ctx->pc != 0x1342DCu) { return; }
    }
    ctx->pc = 0x1342DCu;
label_1342dc:
    // 0x1342dc: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1342dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1342e0: 0xc04b1f8  jal         func_12C7E0
    ctx->pc = 0x1342E0u;
    SET_GPR_U32(ctx, 31, 0x1342E8u);
    ctx->pc = 0x1342E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342E0u;
            // 0x1342e4: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C7E0u;
    if (runtime->hasFunction(0x12C7E0u)) {
        auto targetFn = runtime->lookupFunction(0x12C7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342E8u; }
        if (ctx->pc != 0x1342E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C7E0_0x12c7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342E8u; }
        if (ctx->pc != 0x1342E8u) { return; }
    }
    ctx->pc = 0x1342E8u;
label_1342e8:
    // 0x1342e8: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1342e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1342ec: 0xc04b1f2  jal         func_12C7C8
    ctx->pc = 0x1342ECu;
    SET_GPR_U32(ctx, 31, 0x1342F4u);
    ctx->pc = 0x1342F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342ECu;
            // 0x1342f0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C7C8u;
    if (runtime->hasFunction(0x12C7C8u)) {
        auto targetFn = runtime->lookupFunction(0x12C7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342F4u; }
        if (ctx->pc != 0x1342F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C7C8_0x12c7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1342F4u; }
        if (ctx->pc != 0x1342F4u) { return; }
    }
    ctx->pc = 0x1342F4u;
label_1342f4:
    // 0x1342f4: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1342f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1342f8: 0xc04b236  jal         func_12C8D8
    ctx->pc = 0x1342F8u;
    SET_GPR_U32(ctx, 31, 0x134300u);
    ctx->pc = 0x1342FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1342F8u;
            // 0x1342fc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8D8u;
    if (runtime->hasFunction(0x12C8D8u)) {
        auto targetFn = runtime->lookupFunction(0x12C8D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134300u; }
        if (ctx->pc != 0x134300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C8D8_0x12c8d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134300u; }
        if (ctx->pc != 0x134300u) { return; }
    }
    ctx->pc = 0x134300u;
label_134300:
    // 0x134300: 0xc04b63e  jal         func_12D8F8
    ctx->pc = 0x134300u;
    SET_GPR_U32(ctx, 31, 0x134308u);
    ctx->pc = 0x134304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134300u;
            // 0x134304: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8F8u;
    if (runtime->hasFunction(0x12D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x12D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134308u; }
        if (ctx->pc != 0x134308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8F8_0x12d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134308u; }
        if (ctx->pc != 0x134308u) { return; }
    }
    ctx->pc = 0x134308u;
label_134308:
    // 0x134308: 0x86250040  lh          $a1, 0x40($s1)
    ctx->pc = 0x134308u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x13430c: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x13430cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x134310: 0xc04b1fe  jal         func_12C7F8
    ctx->pc = 0x134310u;
    SET_GPR_U32(ctx, 31, 0x134318u);
    ctx->pc = 0x134314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134310u;
            // 0x134314: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C7F8u;
    if (runtime->hasFunction(0x12C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x12C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134318u; }
        if (ctx->pc != 0x134318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C7F8_0x12c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134318u; }
        if (ctx->pc != 0x134318u) { return; }
    }
    ctx->pc = 0x134318u;
label_134318:
    // 0x134318: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x134318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13431c: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x13431cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x134320: 0xc04cbfa  jal         func_132FE8
    ctx->pc = 0x134320u;
    SET_GPR_U32(ctx, 31, 0x134328u);
    ctx->pc = 0x134324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134320u;
            // 0x134324: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132FE8u;
    if (runtime->hasFunction(0x132FE8u)) {
        auto targetFn = runtime->lookupFunction(0x132FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134328u; }
        if (ctx->pc != 0x134328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132FE8_0x132fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134328u; }
        if (ctx->pc != 0x134328u) { return; }
    }
    ctx->pc = 0x134328u;
label_134328:
    // 0x134328: 0x8fa50020  lw          $a1, 0x20($sp)
    ctx->pc = 0x134328u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13432c: 0x14a00003  bnez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x13432Cu;
    {
        const bool branch_taken_0x13432c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x134330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13432Cu;
            // 0x134330: 0x8fa60024  lw          $a2, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13432c) {
            ctx->pc = 0x13433Cu;
            goto label_13433c;
        }
    }
    ctx->pc = 0x134334u;
    // 0x134334: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x134334u;
    {
        const bool branch_taken_0x134334 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x134334) {
            ctx->pc = 0x134344u;
            goto label_134344;
        }
    }
    ctx->pc = 0x13433Cu;
label_13433c:
    // 0x13433c: 0xc04cbf8  jal         func_132FE0
    ctx->pc = 0x13433Cu;
    SET_GPR_U32(ctx, 31, 0x134344u);
    ctx->pc = 0x134340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13433Cu;
            // 0x134340: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132FE0u;
    if (runtime->hasFunction(0x132FE0u)) {
        auto targetFn = runtime->lookupFunction(0x132FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134344u; }
        if (ctx->pc != 0x134344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132FE0_0x132fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134344u; }
        if (ctx->pc != 0x134344u) { return; }
    }
    ctx->pc = 0x134344u;
label_134344:
    // 0x134344: 0xc04ced2  jal         func_133B48
    ctx->pc = 0x134344u;
    SET_GPR_U32(ctx, 31, 0x13434Cu);
    ctx->pc = 0x134348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134344u;
            // 0x134348: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133B48u;
    if (runtime->hasFunction(0x133B48u)) {
        auto targetFn = runtime->lookupFunction(0x133B48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13434Cu; }
        if (ctx->pc != 0x13434Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133B48_0x133b48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13434Cu; }
        if (ctx->pc != 0x13434Cu) { return; }
    }
    ctx->pc = 0x13434Cu;
label_13434c:
    // 0x13434c: 0x8e240074  lw          $a0, 0x74($s1)
    ctx->pc = 0x13434cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 116)));
    // 0x134350: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x134350u;
    {
        const bool branch_taken_0x134350 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x134350) {
            ctx->pc = 0x134354u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134350u;
            // 0x134354: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134364u;
            goto label_134364;
        }
    }
    ctx->pc = 0x134358u;
    // 0x134358: 0xc048b84  jal         func_122E10
    ctx->pc = 0x134358u;
    SET_GPR_U32(ctx, 31, 0x134360u);
    ctx->pc = 0x13435Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134358u;
            // 0x13435c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122E10u;
    if (runtime->hasFunction(0x122E10u)) {
        auto targetFn = runtime->lookupFunction(0x122E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134360u; }
        if (ctx->pc != 0x134360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122E10_0x122e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134360u; }
        if (ctx->pc != 0x134360u) { return; }
    }
    ctx->pc = 0x134360u;
label_134360:
    // 0x134360: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x134360u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_134364:
    // 0x134364: 0xc04b5de  jal         func_12D778
    ctx->pc = 0x134364u;
    SET_GPR_U32(ctx, 31, 0x13436Cu);
    ctx->pc = 0x134368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134364u;
            // 0x134368: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D778u;
    if (runtime->hasFunction(0x12D778u)) {
        auto targetFn = runtime->lookupFunction(0x12D778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13436Cu; }
        if (ctx->pc != 0x13436Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D778_0x12d778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13436Cu; }
        if (ctx->pc != 0x13436Cu) { return; }
    }
    ctx->pc = 0x13436Cu;
label_13436c:
    // 0x13436c: 0x54500007  bnel        $v0, $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13436Cu;
    {
        const bool branch_taken_0x13436c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        if (branch_taken_0x13436c) {
            ctx->pc = 0x134370u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13436Cu;
            // 0x134370: 0x8e24000c  lw          $a0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13438Cu;
            goto label_13438c;
        }
    }
    ctx->pc = 0x134374u;
    // 0x134374: 0xc04b68c  jal         func_12DA30
    ctx->pc = 0x134374u;
    SET_GPR_U32(ctx, 31, 0x13437Cu);
    ctx->pc = 0x134378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134374u;
            // 0x134378: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA30u;
    if (runtime->hasFunction(0x12DA30u)) {
        auto targetFn = runtime->lookupFunction(0x12DA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13437Cu; }
        if (ctx->pc != 0x13437Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DA30_0x12da30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13437Cu; }
        if (ctx->pc != 0x13437Cu) { return; }
    }
    ctx->pc = 0x13437Cu;
label_13437c:
    // 0x13437c: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x13437cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x134380: 0xc04b23e  jal         func_12C8F8
    ctx->pc = 0x134380u;
    SET_GPR_U32(ctx, 31, 0x134388u);
    ctx->pc = 0x134384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134380u;
            // 0x134384: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8F8u;
    if (runtime->hasFunction(0x12C8F8u)) {
        auto targetFn = runtime->lookupFunction(0x12C8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134388u; }
        if (ctx->pc != 0x134388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C8F8_0x12c8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134388u; }
        if (ctx->pc != 0x134388u) { return; }
    }
    ctx->pc = 0x134388u;
label_134388:
    // 0x134388: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x134388u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_13438c:
    // 0x13438c: 0xc04b1ba  jal         func_12C6E8
    ctx->pc = 0x13438Cu;
    SET_GPR_U32(ctx, 31, 0x134394u);
    ctx->pc = 0x134390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13438Cu;
            // 0x134390: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C6E8u;
    if (runtime->hasFunction(0x12C6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12C6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134394u; }
        if (ctx->pc != 0x134394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C6E8_0x12c6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134394u; }
        if (ctx->pc != 0x134394u) { return; }
    }
    ctx->pc = 0x134394u;
label_134394:
    // 0x134394: 0xa2300001  sb          $s0, 0x1($s1)
    ctx->pc = 0x134394u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 16));
    // 0x134398: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x134398u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_13439c:
    // 0x13439c: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x13439cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1343a0: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1343a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1343a4: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x1343a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1343a8: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x1343a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1343ac: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x1343acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1343b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1343B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1343B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1343B0u;
            // 0x1343b4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134034u: goto label_134034;
            case 0x13405Cu: goto label_13405c;
            case 0x134060u: goto label_134060;
            case 0x134074u: goto label_134074;
            case 0x134078u: goto label_134078;
            case 0x134080u: goto label_134080;
            case 0x134094u: goto label_134094;
            case 0x1340B4u: goto label_1340b4;
            case 0x1340C4u: goto label_1340c4;
            case 0x1340CCu: goto label_1340cc;
            case 0x1340D8u: goto label_1340d8;
            case 0x1340E0u: goto label_1340e0;
            case 0x1340ECu: goto label_1340ec;
            case 0x134108u: goto label_134108;
            case 0x134120u: goto label_134120;
            case 0x13412Cu: goto label_13412c;
            case 0x134148u: goto label_134148;
            case 0x134150u: goto label_134150;
            case 0x134168u: goto label_134168;
            case 0x13417Cu: goto label_13417c;
            case 0x1341A0u: goto label_1341a0;
            case 0x1341A8u: goto label_1341a8;
            case 0x1341B0u: goto label_1341b0;
            case 0x1341E8u: goto label_1341e8;
            case 0x1341FCu: goto label_1341fc;
            case 0x134204u: goto label_134204;
            case 0x13420Cu: goto label_13420c;
            case 0x13421Cu: goto label_13421c;
            case 0x134228u: goto label_134228;
            case 0x134234u: goto label_134234;
            case 0x134248u: goto label_134248;
            case 0x134250u: goto label_134250;
            case 0x134264u: goto label_134264;
            case 0x13426Cu: goto label_13426c;
            case 0x134278u: goto label_134278;
            case 0x134284u: goto label_134284;
            case 0x134290u: goto label_134290;
            case 0x1342A4u: goto label_1342a4;
            case 0x1342ACu: goto label_1342ac;
            case 0x1342B8u: goto label_1342b8;
            case 0x1342C4u: goto label_1342c4;
            case 0x1342D0u: goto label_1342d0;
            case 0x1342DCu: goto label_1342dc;
            case 0x1342E8u: goto label_1342e8;
            case 0x1342F4u: goto label_1342f4;
            case 0x134300u: goto label_134300;
            case 0x134308u: goto label_134308;
            case 0x134318u: goto label_134318;
            case 0x134328u: goto label_134328;
            case 0x13433Cu: goto label_13433c;
            case 0x134344u: goto label_134344;
            case 0x13434Cu: goto label_13434c;
            case 0x134360u: goto label_134360;
            case 0x134364u: goto label_134364;
            case 0x13436Cu: goto label_13436c;
            case 0x13437Cu: goto label_13437c;
            case 0x134388u: goto label_134388;
            case 0x13438Cu: goto label_13438c;
            case 0x134394u: goto label_134394;
            case 0x13439Cu: goto label_13439c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1343B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
