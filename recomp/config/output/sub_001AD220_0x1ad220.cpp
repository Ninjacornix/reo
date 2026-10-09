#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD220
// Address: 0x1ad220 - 0x1ad410
void sub_001AD220_0x1ad220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD220_0x1ad220");
#endif

    switch (ctx->pc) {
        case 0x1ad298u: goto label_1ad298;
        case 0x1ad2a0u: goto label_1ad2a0;
        case 0x1ad328u: goto label_1ad328;
        case 0x1ad340u: goto label_1ad340;
        case 0x1ad37cu: goto label_1ad37c;
        case 0x1ad3a8u: goto label_1ad3a8;
        case 0x1ad3c4u: goto label_1ad3c4;
        case 0x1ad3d4u: goto label_1ad3d4;
        case 0x1ad3dcu: goto label_1ad3dc;
        default: break;
    }

    ctx->pc = 0x1ad220u;

    // 0x1ad220: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1ad220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1ad224: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1ad224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1ad228: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ad228u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ad22c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ad22cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ad230: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1ad230u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad234: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ad234u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ad238: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1ad238u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad23c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ad23cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ad240: 0x2e820010  sltiu       $v0, $s4, 0x10
    ctx->pc = 0x1ad240u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1ad244: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad244u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad248: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD248u;
    {
        const bool branch_taken_0x1ad248 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD248u;
            // 0x1ad24c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad248) {
            ctx->pc = 0x1AD258u;
            goto label_1ad258;
        }
    }
    ctx->pc = 0x1AD250u;
    // 0x1ad250: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1AD250u;
    {
        const bool branch_taken_0x1ad250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD250u;
            // 0x1ad254: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad250) {
            ctx->pc = 0x1AD3E0u;
            goto label_1ad3e0;
        }
    }
    ctx->pc = 0x1AD258u;
label_1ad258:
    // 0x1ad258: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ad258u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ad25c: 0x141040  sll         $v0, $s4, 1
    ctx->pc = 0x1ad25cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x1ad260: 0x8c33440c  lw          $s3, 0x440C($at)
    ctx->pc = 0x1ad260u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1ad264: 0x541821  addu        $v1, $v0, $s4
    ctx->pc = 0x1ad264u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1ad268: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1ad268u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ad26c: 0x31a40  sll         $v1, $v1, 9
    ctx->pc = 0x1ad26cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 9));
    // 0x1ad270: 0x24423950  addiu       $v0, $v0, 0x3950
    ctx->pc = 0x1ad270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14672));
    // 0x1ad274: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad278: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1ad278u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ad27c: 0x24060600  addiu       $a2, $zero, 0x600
    ctx->pc = 0x1ad27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x1ad280: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ad280u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad284: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x1ad284u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad288: 0x8e620020  lw          $v0, 0x20($s3)
    ctx->pc = 0x1ad288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x1ad28c: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x1ad28cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1ad290: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD290u;
    SET_GPR_U32(ctx, 31, 0x1AD298u);
    ctx->pc = 0x1AD294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD290u;
            // 0x1ad294: 0x24520010  addiu       $s2, $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD298u; }
        if (ctx->pc != 0x1AD298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD298u; }
        if (ctx->pc != 0x1AD298u) { return; }
    }
    ctx->pc = 0x1AD298u;
label_1ad298:
    // 0x1ad298: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1AD298u;
    {
        const bool branch_taken_0x1ad298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD298u;
            // 0x1ad29c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad298) {
            ctx->pc = 0x1AD2F8u;
            goto label_1ad2f8;
        }
    }
    ctx->pc = 0x1AD2A0u;
label_1ad2a0:
    // 0x1ad2a0: 0x82420000  lb          $v0, 0x0($s2)
    ctx->pc = 0x1ad2a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ad2a4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ad2a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ad2a8: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1ad2a8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2ac: 0x82420009  lb          $v0, 0x9($s2)
    ctx->pc = 0x1ad2acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
    // 0x1ad2b0: 0xa2220005  sb          $v0, 0x5($s1)
    ctx->pc = 0x1ad2b0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 5), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2b4: 0x82420006  lb          $v0, 0x6($s2)
    ctx->pc = 0x1ad2b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1ad2b8: 0x3042007f  andi        $v0, $v0, 0x7F
    ctx->pc = 0x1ad2b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x1ad2bc: 0xa2220008  sb          $v0, 0x8($s1)
    ctx->pc = 0x1ad2bcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 8), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2c0: 0x82420006  lb          $v0, 0x6($s2)
    ctx->pc = 0x1ad2c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1ad2c4: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1ad2c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1ad2c8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1ad2c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1ad2cc: 0xa2220009  sb          $v0, 0x9($s1)
    ctx->pc = 0x1ad2ccu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 9), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2d0: 0x82420008  lb          $v0, 0x8($s2)
    ctx->pc = 0x1ad2d0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1ad2d4: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1ad2d4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2d8: 0x8242000c  lb          $v0, 0xC($s2)
    ctx->pc = 0x1ad2d8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1ad2dc: 0xa2220006  sb          $v0, 0x6($s1)
    ctx->pc = 0x1ad2dcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 6), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2e0: 0x8242000d  lb          $v0, 0xD($s2)
    ctx->pc = 0x1ad2e0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 13)));
    // 0x1ad2e4: 0xa2220007  sb          $v0, 0x7($s1)
    ctx->pc = 0x1ad2e4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2e8: 0x8242000f  lb          $v0, 0xF($s2)
    ctx->pc = 0x1ad2e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 15)));
    // 0x1ad2ec: 0xa222000b  sb          $v0, 0xB($s1)
    ctx->pc = 0x1ad2ecu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 11), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad2f0: 0x26520010  addiu       $s2, $s2, 0x10
    ctx->pc = 0x1ad2f0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1ad2f4: 0x2631000c  addiu       $s1, $s1, 0xC
    ctx->pc = 0x1ad2f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
label_1ad2f8:
    // 0x1ad2f8: 0x28610080  slti        $at, $v1, 0x80
    ctx->pc = 0x1ad2f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1ad2fc: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AD2FCu;
    {
        const bool branch_taken_0x1ad2fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD2FCu;
            // 0x1ad300: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad2fc) {
            ctx->pc = 0x1AD31Cu;
            goto label_1ad31c;
        }
    }
    ctx->pc = 0x1AD304u;
    // 0x1ad304: 0x8e620024  lw          $v0, 0x24($s3)
    ctx->pc = 0x1ad304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 36)));
    // 0x1ad308: 0x2442fff0  addiu       $v0, $v0, -0x10
    ctx->pc = 0x1ad308u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
    // 0x1ad30c: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ad30cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ad310: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1ad310u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1ad314: 0x1440ffe2  bnez        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1AD314u;
    {
        const bool branch_taken_0x1ad314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ad314) {
            ctx->pc = 0x1AD2A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ad2a0;
        }
    }
    ctx->pc = 0x1AD31Cu;
label_1ad31c:
    // 0x1ad31c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad31cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad320: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD320u;
    SET_GPR_U32(ctx, 31, 0x1AD328u);
    ctx->pc = 0x1AD324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD320u;
            // 0x1ad324: 0x3c060004  lui         $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD328u; }
        if (ctx->pc != 0x1AD328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD328u; }
        if (ctx->pc != 0x1AD328u) { return; }
    }
    ctx->pc = 0x1AD328u;
label_1ad328:
    // 0x1ad328: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad328u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad32c: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1ad32cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1ad330: 0x8c243810  lw          $a0, 0x3810($at)
    ctx->pc = 0x1ad330u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14352)));
    // 0x1ad334: 0x24a53814  addiu       $a1, $a1, 0x3814
    ctx->pc = 0x1ad334u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14356));
    // 0x1ad338: 0xc06f9b4  jal         func_1BE6D0
    ctx->pc = 0x1AD338u;
    SET_GPR_U32(ctx, 31, 0x1AD340u);
    ctx->pc = 0x1AD33Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD338u;
            // 0x1ad33c: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE6D0u;
    if (runtime->hasFunction(0x1BE6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BE6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD340u; }
        if (ctx->pc != 0x1AD340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE6D0_0x1be6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD340u; }
        if (ctx->pc != 0x1AD340u) { return; }
    }
    ctx->pc = 0x1AD340u;
label_1ad340:
    // 0x1ad340: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad344: 0x8e67001c  lw          $a3, 0x1C($s3)
    ctx->pc = 0x1ad344u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1ad348: 0x8c263828  lw          $a2, 0x3828($at)
    ctx->pc = 0x1ad348u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14376)));
    // 0x1ad34c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1ad34cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad350: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1ad350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1ad354: 0x3c01000b  lui         $at, 0xB
    ctx->pc = 0x1ad354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)11 << 16));
    // 0x1ad358: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1ad358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1ad35c: 0x3421ffe1  ori         $at, $at, 0xFFE1
    ctx->pc = 0x1ad35cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65505);
    // 0x1ad360: 0x41082a  slt         $at, $v0, $at
    ctx->pc = 0x1ad360u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1ad364: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AD364u;
    {
        const bool branch_taken_0x1ad364 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ad364) {
            ctx->pc = 0x1AD37Cu;
            goto label_1ad37c;
        }
    }
    ctx->pc = 0x1AD36Cu;
    // 0x1ad36c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ad36cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ad370: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1ad370u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad374: 0xc06ce0c  jal         func_1B3830
    ctx->pc = 0x1AD374u;
    SET_GPR_U32(ctx, 31, 0x1AD37Cu);
    ctx->pc = 0x1AD378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD374u;
            // 0x1ad378: 0x2484fde8  addiu       $a0, $a0, -0x218 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966760));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3830u;
    if (runtime->hasFunction(0x1B3830u)) {
        auto targetFn = runtime->lookupFunction(0x1B3830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD37Cu; }
        if (ctx->pc != 0x1AD37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3830_0x1b3830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD37Cu; }
        if (ctx->pc != 0x1AD37Cu) { return; }
    }
    ctx->pc = 0x1AD37Cu;
label_1ad37c:
    // 0x1ad37c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad37cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad380: 0x8e620018  lw          $v0, 0x18($s3)
    ctx->pc = 0x1ad380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1ad384: 0x8c273830  lw          $a3, 0x3830($at)
    ctx->pc = 0x1ad384u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14384)));
    // 0x1ad388: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1ad388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad38c: 0x8e6a001c  lw          $t2, 0x1C($s3)
    ctx->pc = 0x1ad38cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1ad390: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1ad390u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad394: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1ad394u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad398: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad39c: 0x8c283828  lw          $t0, 0x3828($at)
    ctx->pc = 0x1ad39cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14376)));
    // 0x1ad3a0: 0xc069e40  jal         func_1A7900
    ctx->pc = 0x1AD3A0u;
    SET_GPR_U32(ctx, 31, 0x1AD3A8u);
    ctx->pc = 0x1AD3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3A0u;
            // 0x1ad3a4: 0x2624821  addu        $t1, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7900u;
    if (runtime->hasFunction(0x1A7900u)) {
        auto targetFn = runtime->lookupFunction(0x1A7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3A8u; }
        if (ctx->pc != 0x1AD3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7900_0x1a7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3A8u; }
        if (ctx->pc != 0x1AD3A8u) { return; }
    }
    ctx->pc = 0x1AD3A8u;
label_1ad3a8:
    // 0x1ad3a8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1ad3a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad3ac: 0x6210007  bgez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AD3ACu;
    {
        const bool branch_taken_0x1ad3ac = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1AD3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3ACu;
            // 0x1ad3b0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad3ac) {
            ctx->pc = 0x1AD3CCu;
            goto label_1ad3cc;
        }
    }
    ctx->pc = 0x1AD3B4u;
    // 0x1ad3b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ad3b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad3b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad3b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad3bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD3BCu;
    SET_GPR_U32(ctx, 31, 0x1AD3C4u);
    ctx->pc = 0x1AD3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3BCu;
            // 0x1ad3c0: 0x24060600  addiu       $a2, $zero, 0x600 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3C4u; }
        if (ctx->pc != 0x1AD3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3C4u; }
        if (ctx->pc != 0x1AD3C4u) { return; }
    }
    ctx->pc = 0x1AD3C4u;
label_1ad3c4:
    // 0x1ad3c4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AD3C4u;
    {
        const bool branch_taken_0x1ad3c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3C4u;
            // 0x1ad3c8: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad3c4) {
            ctx->pc = 0x1AD3E0u;
            goto label_1ad3e0;
        }
    }
    ctx->pc = 0x1AD3CCu;
label_1ad3cc:
    // 0x1ad3cc: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1AD3CCu;
    SET_GPR_U32(ctx, 31, 0x1AD3D4u);
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3D4u; }
        if (ctx->pc != 0x1AD3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3D4u; }
        if (ctx->pc != 0x1AD3D4u) { return; }
    }
    ctx->pc = 0x1AD3D4u;
label_1ad3d4:
    // 0x1ad3d4: 0xc069f78  jal         func_1A7DE0
    ctx->pc = 0x1AD3D4u;
    SET_GPR_U32(ctx, 31, 0x1AD3DCu);
    ctx->pc = 0x1AD3D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3D4u;
            // 0x1ad3d8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7DE0u;
    if (runtime->hasFunction(0x1A7DE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3DCu; }
        if (ctx->pc != 0x1AD3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7DE0_0x1a7de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD3DCu; }
        if (ctx->pc != 0x1AD3DCu) { return; }
    }
    ctx->pc = 0x1AD3DCu;
label_1ad3dc:
    // 0x1ad3dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ad3dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ad3e0:
    // 0x1ad3e0: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1ad3e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ad3e4: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ad3e4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ad3e8: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ad3e8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ad3ec: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ad3ecu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ad3f0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ad3f0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad3f4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad3f4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad3f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad3f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad3fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD3FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD3FCu;
            // 0x1ad400: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD258u: goto label_1ad258;
            case 0x1AD298u: goto label_1ad298;
            case 0x1AD2A0u: goto label_1ad2a0;
            case 0x1AD2F8u: goto label_1ad2f8;
            case 0x1AD31Cu: goto label_1ad31c;
            case 0x1AD328u: goto label_1ad328;
            case 0x1AD340u: goto label_1ad340;
            case 0x1AD37Cu: goto label_1ad37c;
            case 0x1AD3A8u: goto label_1ad3a8;
            case 0x1AD3C4u: goto label_1ad3c4;
            case 0x1AD3CCu: goto label_1ad3cc;
            case 0x1AD3D4u: goto label_1ad3d4;
            case 0x1AD3DCu: goto label_1ad3dc;
            case 0x1AD3E0u: goto label_1ad3e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD404u;
    // 0x1ad404: 0x0  nop
    ctx->pc = 0x1ad404u;
    // NOP
    // 0x1ad408: 0x0  nop
    ctx->pc = 0x1ad408u;
    // NOP
    // 0x1ad40c: 0x0  nop
    ctx->pc = 0x1ad40cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
