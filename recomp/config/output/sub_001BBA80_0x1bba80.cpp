#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBA80
// Address: 0x1bba80 - 0x1bbf70
void sub_001BBA80_0x1bba80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBA80_0x1bba80");
#endif

    switch (ctx->pc) {
        case 0x1bbb34u: goto label_1bbb34;
        case 0x1bbbb8u: goto label_1bbbb8;
        default: break;
    }

    ctx->pc = 0x1bba80u;

    // 0x1bba80: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba84: 0x24060280  addiu       $a2, $zero, 0x280
    ctx->pc = 0x1bba84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bba88: 0xa4246632  sh          $a0, 0x6632($at)
    ctx->pc = 0x1bba88u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26162), (uint16_t)GPR_U32(ctx, 4));
    // 0x1bba8c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba90: 0x240401c0  addiu       $a0, $zero, 0x1C0
    ctx->pc = 0x1bba90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 448));
    // 0x1bba94: 0xa420662e  sh          $zero, 0x662E($at)
    ctx->pc = 0x1bba94u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26158), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bba98: 0x851823  subu        $v1, $a0, $a1
    ctx->pc = 0x1bba98u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1bba9c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbaa0: 0xa420662c  sh          $zero, 0x662C($at)
    ctx->pc = 0x1bbaa0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26156), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bbaa4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbaa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbaa8: 0xa424663e  sh          $a0, 0x663E($at)
    ctx->pc = 0x1bbaa8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26174), (uint16_t)GPR_U32(ctx, 4));
    // 0x1bbaac: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbaacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbab0: 0xa423663a  sh          $v1, 0x663A($at)
    ctx->pc = 0x1bbab0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26170), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bbab4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbab4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbab8: 0xa4266630  sh          $a2, 0x6630($at)
    ctx->pc = 0x1bbab8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26160), (uint16_t)GPR_U32(ctx, 6));
    // 0x1bbabc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbabcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbac0: 0xa426663c  sh          $a2, 0x663C($at)
    ctx->pc = 0x1bbac0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26172), (uint16_t)GPR_U32(ctx, 6));
    // 0x1bbac4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbac4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbac8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBAC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBAC8u;
            // 0x1bbacc: 0xa4206638  sh          $zero, 0x6638($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 26168), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            case 0x1BBB94u: goto label_1bbb94;
            case 0x1BBBB8u: goto label_1bbbb8;
            case 0x1BBBF8u: goto label_1bbbf8;
            case 0x1BBC00u: goto label_1bbc00;
            case 0x1BBC18u: goto label_1bbc18;
            case 0x1BBC54u: goto label_1bbc54;
            case 0x1BBC80u: goto label_1bbc80;
            case 0x1BBC94u: goto label_1bbc94;
            case 0x1BBCB4u: goto label_1bbcb4;
            case 0x1BBCD4u: goto label_1bbcd4;
            case 0x1BBCF0u: goto label_1bbcf0;
            case 0x1BBD04u: goto label_1bbd04;
            case 0x1BBD1Cu: goto label_1bbd1c;
            case 0x1BBD34u: goto label_1bbd34;
            case 0x1BBD50u: goto label_1bbd50;
            case 0x1BBD74u: goto label_1bbd74;
            case 0x1BBD90u: goto label_1bbd90;
            case 0x1BBDA4u: goto label_1bbda4;
            case 0x1BBDBCu: goto label_1bbdbc;
            case 0x1BBDD4u: goto label_1bbdd4;
            case 0x1BBDF0u: goto label_1bbdf0;
            case 0x1BBE1Cu: goto label_1bbe1c;
            case 0x1BBE38u: goto label_1bbe38;
            case 0x1BBE4Cu: goto label_1bbe4c;
            case 0x1BBE64u: goto label_1bbe64;
            case 0x1BBE7Cu: goto label_1bbe7c;
            case 0x1BBE98u: goto label_1bbe98;
            case 0x1BBEC4u: goto label_1bbec4;
            case 0x1BBEE0u: goto label_1bbee0;
            case 0x1BBEF4u: goto label_1bbef4;
            case 0x1BBF0Cu: goto label_1bbf0c;
            case 0x1BBF24u: goto label_1bbf24;
            case 0x1BBF40u: goto label_1bbf40;
            case 0x1BBF5Cu: goto label_1bbf5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBAD0u;
    // 0x1bbad0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbad0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbad4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bbad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bbad8: 0xac246624  sw          $a0, 0x6624($at)
    ctx->pc = 0x1bbad8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26148), GPR_U32(ctx, 4));
    // 0x1bbadc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbadcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbae0: 0xac246628  sw          $a0, 0x6628($at)
    ctx->pc = 0x1bbae0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26152), GPR_U32(ctx, 4));
    // 0x1bbae4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbae4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbae8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bbae8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bbaec: 0xac206634  sw          $zero, 0x6634($at)
    ctx->pc = 0x1bbaecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 0));
    // 0x1bbaf0: 0x65200b  movn        $a0, $v1, $a1
    ctx->pc = 0x1bbaf0u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x1bbaf4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbaf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbaf8: 0xac206640  sw          $zero, 0x6640($at)
    ctx->pc = 0x1bbaf8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26176), GPR_U32(ctx, 0));
    // 0x1bbafc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbafcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb00: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB00u;
            // 0x1bbb04: 0xa0246620  sb          $a0, 0x6620($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 26144), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            case 0x1BBB94u: goto label_1bbb94;
            case 0x1BBBB8u: goto label_1bbbb8;
            case 0x1BBBF8u: goto label_1bbbf8;
            case 0x1BBC00u: goto label_1bbc00;
            case 0x1BBC18u: goto label_1bbc18;
            case 0x1BBC54u: goto label_1bbc54;
            case 0x1BBC80u: goto label_1bbc80;
            case 0x1BBC94u: goto label_1bbc94;
            case 0x1BBCB4u: goto label_1bbcb4;
            case 0x1BBCD4u: goto label_1bbcd4;
            case 0x1BBCF0u: goto label_1bbcf0;
            case 0x1BBD04u: goto label_1bbd04;
            case 0x1BBD1Cu: goto label_1bbd1c;
            case 0x1BBD34u: goto label_1bbd34;
            case 0x1BBD50u: goto label_1bbd50;
            case 0x1BBD74u: goto label_1bbd74;
            case 0x1BBD90u: goto label_1bbd90;
            case 0x1BBDA4u: goto label_1bbda4;
            case 0x1BBDBCu: goto label_1bbdbc;
            case 0x1BBDD4u: goto label_1bbdd4;
            case 0x1BBDF0u: goto label_1bbdf0;
            case 0x1BBE1Cu: goto label_1bbe1c;
            case 0x1BBE38u: goto label_1bbe38;
            case 0x1BBE4Cu: goto label_1bbe4c;
            case 0x1BBE64u: goto label_1bbe64;
            case 0x1BBE7Cu: goto label_1bbe7c;
            case 0x1BBE98u: goto label_1bbe98;
            case 0x1BBEC4u: goto label_1bbec4;
            case 0x1BBEE0u: goto label_1bbee0;
            case 0x1BBEF4u: goto label_1bbef4;
            case 0x1BBF0Cu: goto label_1bbf0c;
            case 0x1BBF24u: goto label_1bbf24;
            case 0x1BBF40u: goto label_1bbf40;
            case 0x1BBF5Cu: goto label_1bbf5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBB08u;
    // 0x1bbb08: 0x0  nop
    ctx->pc = 0x1bbb08u;
    // NOP
    // 0x1bbb0c: 0x0  nop
    ctx->pc = 0x1bbb0cu;
    // NOP
    // 0x1bbb10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bbb10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bbb14: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bbb14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bbb18: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bbb18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bbb1c: 0x24060018  addiu       $a2, $zero, 0x18
    ctx->pc = 0x1bbb1cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1bbb20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bbb20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bbb24: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bbb24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bbb28: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bbb28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb2c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BBB2Cu;
    SET_GPR_U32(ctx, 31, 0x1BBB34u);
    ctx->pc = 0x1BBB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB2Cu;
            // 0x1bbb30: 0x24846600  addiu       $a0, $a0, 0x6600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBB34u; }
        if (ctx->pc != 0x1BBB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBB34u; }
        if (ctx->pc != 0x1BBB34u) { return; }
    }
    ctx->pc = 0x1BBB34u;
label_1bbb34:
    // 0x1bbb34: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb38: 0x24030280  addiu       $v1, $zero, 0x280
    ctx->pc = 0x1bbb38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bbb3c: 0xac306614  sw          $s0, 0x6614($at)
    ctx->pc = 0x1bbb3cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26132), GPR_U32(ctx, 16));
    // 0x1bbb40: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb44: 0xa4236610  sh          $v1, 0x6610($at)
    ctx->pc = 0x1bbb44u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26128), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bbb48: 0x240301e0  addiu       $v1, $zero, 0x1E0
    ctx->pc = 0x1bbb48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 480));
    // 0x1bbb4c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb50: 0xa4236612  sh          $v1, 0x6612($at)
    ctx->pc = 0x1bbb50u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26130), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bbb54: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1bbb54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1bbb58: 0xac20eb10  sw          $zero, -0x14F0($at)
    ctx->pc = 0x1bbb58u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961936), GPR_U32(ctx, 0));
    // 0x1bbb5c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb60: 0xa420660c  sh          $zero, 0x660C($at)
    ctx->pc = 0x1bbb60u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26124), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bbb64: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb68: 0xa420660e  sh          $zero, 0x660E($at)
    ctx->pc = 0x1bbb68u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26126), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bbb6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bbb6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bbb70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bbb70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bbb74: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB74u;
            // 0x1bbb78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            case 0x1BBB94u: goto label_1bbb94;
            case 0x1BBBB8u: goto label_1bbbb8;
            case 0x1BBBF8u: goto label_1bbbf8;
            case 0x1BBC00u: goto label_1bbc00;
            case 0x1BBC18u: goto label_1bbc18;
            case 0x1BBC54u: goto label_1bbc54;
            case 0x1BBC80u: goto label_1bbc80;
            case 0x1BBC94u: goto label_1bbc94;
            case 0x1BBCB4u: goto label_1bbcb4;
            case 0x1BBCD4u: goto label_1bbcd4;
            case 0x1BBCF0u: goto label_1bbcf0;
            case 0x1BBD04u: goto label_1bbd04;
            case 0x1BBD1Cu: goto label_1bbd1c;
            case 0x1BBD34u: goto label_1bbd34;
            case 0x1BBD50u: goto label_1bbd50;
            case 0x1BBD74u: goto label_1bbd74;
            case 0x1BBD90u: goto label_1bbd90;
            case 0x1BBDA4u: goto label_1bbda4;
            case 0x1BBDBCu: goto label_1bbdbc;
            case 0x1BBDD4u: goto label_1bbdd4;
            case 0x1BBDF0u: goto label_1bbdf0;
            case 0x1BBE1Cu: goto label_1bbe1c;
            case 0x1BBE38u: goto label_1bbe38;
            case 0x1BBE4Cu: goto label_1bbe4c;
            case 0x1BBE64u: goto label_1bbe64;
            case 0x1BBE7Cu: goto label_1bbe7c;
            case 0x1BBE98u: goto label_1bbe98;
            case 0x1BBEC4u: goto label_1bbec4;
            case 0x1BBEE0u: goto label_1bbee0;
            case 0x1BBEF4u: goto label_1bbef4;
            case 0x1BBF0Cu: goto label_1bbf0c;
            case 0x1BBF24u: goto label_1bbf24;
            case 0x1BBF40u: goto label_1bbf40;
            case 0x1BBF5Cu: goto label_1bbf5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBB7Cu;
    // 0x1bbb7c: 0x0  nop
    ctx->pc = 0x1bbb7cu;
    // NOP
    // 0x1bbb80: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x1bbb80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bbb84: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bbb84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bbb88: 0x14a30002  bne         $a1, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BBB88u;
    {
        const bool branch_taken_0x1bbb88 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1BBB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB88u;
            // 0x1bbb8c: 0x3c010039  lui         $at, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbb88) {
            ctx->pc = 0x1BBB94u;
            goto label_1bbb94;
        }
    }
    ctx->pc = 0x1BBB90u;
    // 0x1bbb90: 0xac24eb10  sw          $a0, -0x14F0($at)
    ctx->pc = 0x1bbb90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961936), GPR_U32(ctx, 4));
label_1bbb94:
    // 0x1bbb94: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            case 0x1BBB94u: goto label_1bbb94;
            case 0x1BBBB8u: goto label_1bbbb8;
            case 0x1BBBF8u: goto label_1bbbf8;
            case 0x1BBC00u: goto label_1bbc00;
            case 0x1BBC18u: goto label_1bbc18;
            case 0x1BBC54u: goto label_1bbc54;
            case 0x1BBC80u: goto label_1bbc80;
            case 0x1BBC94u: goto label_1bbc94;
            case 0x1BBCB4u: goto label_1bbcb4;
            case 0x1BBCD4u: goto label_1bbcd4;
            case 0x1BBCF0u: goto label_1bbcf0;
            case 0x1BBD04u: goto label_1bbd04;
            case 0x1BBD1Cu: goto label_1bbd1c;
            case 0x1BBD34u: goto label_1bbd34;
            case 0x1BBD50u: goto label_1bbd50;
            case 0x1BBD74u: goto label_1bbd74;
            case 0x1BBD90u: goto label_1bbd90;
            case 0x1BBDA4u: goto label_1bbda4;
            case 0x1BBDBCu: goto label_1bbdbc;
            case 0x1BBDD4u: goto label_1bbdd4;
            case 0x1BBDF0u: goto label_1bbdf0;
            case 0x1BBE1Cu: goto label_1bbe1c;
            case 0x1BBE38u: goto label_1bbe38;
            case 0x1BBE4Cu: goto label_1bbe4c;
            case 0x1BBE64u: goto label_1bbe64;
            case 0x1BBE7Cu: goto label_1bbe7c;
            case 0x1BBE98u: goto label_1bbe98;
            case 0x1BBEC4u: goto label_1bbec4;
            case 0x1BBEE0u: goto label_1bbee0;
            case 0x1BBEF4u: goto label_1bbef4;
            case 0x1BBF0Cu: goto label_1bbf0c;
            case 0x1BBF24u: goto label_1bbf24;
            case 0x1BBF40u: goto label_1bbf40;
            case 0x1BBF5Cu: goto label_1bbf5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBB9Cu;
    // 0x1bbb9c: 0x0  nop
    ctx->pc = 0x1bbb9cu;
    // NOP
    // 0x1bbba0: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1bbba0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1bbba4: 0x8c23eb10  lw          $v1, -0x14F0($at)
    ctx->pc = 0x1bbba4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961936)));
    // 0x1bbba8: 0x106000ec  beqz        $v1, . + 4 + (0xEC << 2)
    ctx->pc = 0x1BBBA8u;
    {
        const bool branch_taken_0x1bbba8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBBA8u;
            // 0x1bbbac: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbba8) {
            ctx->pc = 0x1BBF5Cu;
            goto label_1bbf5c;
        }
    }
    ctx->pc = 0x1BBBB0u;
    // 0x1bbbb0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1bbbb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bbbb4: 0x72880  sll         $a1, $a3, 2
    ctx->pc = 0x1bbbb4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
label_1bbbb8:
    // 0x1bbbb8: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1bbbb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1bbbbc: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x1bbbbcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1bbbc0: 0x652821  addu        $a1, $v1, $a1
    ctx->pc = 0x1bbbc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1bbbc4: 0x8ca60004  lw          $a2, 0x4($a1)
    ctx->pc = 0x1bbbc4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1bbbc8: 0x14c4000d  bne         $a2, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1BBBC8u;
    {
        const bool branch_taken_0x1bbbc8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        if (branch_taken_0x1bbbc8) {
            ctx->pc = 0x1BBC00u;
            goto label_1bbc00;
        }
    }
    ctx->pc = 0x1BBBD0u;
    // 0x1bbbd0: 0x94a60002  lhu         $a2, 0x2($a1)
    ctx->pc = 0x1bbbd0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1bbbd4: 0x3404ffff  ori         $a0, $zero, 0xFFFF
    ctx->pc = 0x1bbbd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1bbbd8: 0x10c40007  beq         $a2, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBBD8u;
    {
        const bool branch_taken_0x1bbbd8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 4));
        if (branch_taken_0x1bbbd8) {
            ctx->pc = 0x1BBBF8u;
            goto label_1bbbf8;
        }
    }
    ctx->pc = 0x1BBBE0u;
    // 0x1bbbe0: 0x94640002  lhu         $a0, 0x2($v1)
    ctx->pc = 0x1bbbe0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1bbbe4: 0x86082a  slt         $at, $a0, $a2
    ctx->pc = 0x1bbbe4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1bbbe8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BBBE8u;
    {
        const bool branch_taken_0x1bbbe8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bbbe8) {
            ctx->pc = 0x1BBBF8u;
            goto label_1bbbf8;
        }
    }
    ctx->pc = 0x1BBBF0u;
    // 0x1bbbf0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BBBF0u;
    {
        const bool branch_taken_0x1bbbf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bbbf0) {
            ctx->pc = 0x1BBC18u;
            goto label_1bbc18;
        }
    }
    ctx->pc = 0x1BBBF8u;
label_1bbbf8:
    // 0x1bbbf8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBBF8u;
    {
        const bool branch_taken_0x1bbbf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBBFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBBF8u;
            // 0x1bbbfc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbbf8) {
            ctx->pc = 0x1BBC18u;
            goto label_1bbc18;
        }
    }
    ctx->pc = 0x1BBC00u;
label_1bbc00:
    // 0x1bbc00: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1bbc00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1bbc04: 0x28e10021  slti        $at, $a3, 0x21
    ctx->pc = 0x1bbc04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1bbc08: 0x1420ffeb  bnez        $at, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1BBC08u;
    {
        const bool branch_taken_0x1bbc08 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BBC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBC08u;
            // 0x1bbc0c: 0x72880  sll         $a1, $a3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbc08) {
            ctx->pc = 0x1BBBB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bbbb8;
        }
    }
    ctx->pc = 0x1BBC10u;
    // 0x1bbc10: 0x100000d2  b           . + 4 + (0xD2 << 2)
    ctx->pc = 0x1BBC10u;
    {
        const bool branch_taken_0x1bbc10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bbc10) {
            ctx->pc = 0x1BBF5Cu;
            goto label_1bbf5c;
        }
    }
    ctx->pc = 0x1BBC18u;
label_1bbc18:
    // 0x1bbc18: 0x14a0000e  bnez        $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1BBC18u;
    {
        const bool branch_taken_0x1bbc18 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bbc18) {
            ctx->pc = 0x1BBC54u;
            goto label_1bbc54;
        }
    }
    ctx->pc = 0x1BBC20u;
    // 0x1bbc20: 0x9466000e  lhu         $a2, 0xE($v1)
    ctx->pc = 0x1bbc20u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1bbc24: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbc24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbc28: 0x94650008  lhu         $a1, 0x8($v1)
    ctx->pc = 0x1bbc28u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1bbc2c: 0x9464000a  lhu         $a0, 0xA($v1)
    ctx->pc = 0x1bbc2cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x1bbc30: 0x63600  sll         $a2, $a2, 24
    ctx->pc = 0x1bbc30u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 24));
    // 0x1bbc34: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1bbc34u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1bbc38: 0x9463000c  lhu         $v1, 0xC($v1)
    ctx->pc = 0x1bbc38u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1bbc3c: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1bbc3cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1bbc40: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x1bbc40u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1bbc44: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1bbc44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1bbc48: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1bbc48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1bbc4c: 0x100000c3  b           . + 4 + (0xC3 << 2)
    ctx->pc = 0x1BBC4Cu;
    {
        const bool branch_taken_0x1bbc4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBC4Cu;
            // 0x1bbc50: 0xac236614  sw          $v1, 0x6614($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26132), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbc4c) {
            ctx->pc = 0x1BBF5Cu;
            goto label_1bbf5c;
        }
    }
    ctx->pc = 0x1BBC54u;
label_1bbc54:
    // 0x1bbc54: 0x94660002  lhu         $a2, 0x2($v1)
    ctx->pc = 0x1bbc54u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1bbc58: 0x94a40002  lhu         $a0, 0x2($a1)
    ctx->pc = 0x1bbc58u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1bbc5c: 0x63842  srl         $a3, $a2, 1
    ctx->pc = 0x1bbc5cu;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 1));
    // 0x1bbc60: 0x42042  srl         $a0, $a0, 1
    ctx->pc = 0x1bbc60u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x1bbc64: 0x874023  subu        $t0, $a0, $a3
    ctx->pc = 0x1bbc64u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bbc68: 0x15000005  bnez        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BBC68u;
    {
        const bool branch_taken_0x1bbc68 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BBC6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBC68u;
            // 0x1bbc6c: 0x3c010039  lui         $at, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbc68) {
            ctx->pc = 0x1BBC80u;
            goto label_1bbc80;
        }
    }
    ctx->pc = 0x1BBC70u;
    // 0x1bbc70: 0x3c043f80  lui         $a0, 0x3F80
    ctx->pc = 0x1bbc70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16256 << 16));
    // 0x1bbc74: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bbc74u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bbc78: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BBC78u;
    {
        const bool branch_taken_0x1bbc78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBC78u;
            // 0x1bbc7c: 0x94690008  lhu         $t1, 0x8($v1) (Delay Slot)
        SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbc78) {
            ctx->pc = 0x1BBCB4u;
            goto label_1bbcb4;
        }
    }
    ctx->pc = 0x1BBC80u;
label_1bbc80:
    // 0x1bbc80: 0x8c26eca8  lw          $a2, -0x1358($at)
    ctx->pc = 0x1bbc80u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962344)));
    // 0x1bbc84: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BBC84u;
    {
        const bool branch_taken_0x1bbc84 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1BBC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBC84u;
            // 0x1bbc88: 0x62043  sra         $a0, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbc84) {
            ctx->pc = 0x1BBC94u;
            goto label_1bbc94;
        }
    }
    ctx->pc = 0x1BBC8Cu;
    // 0x1bbc8c: 0x24c40001  addiu       $a0, $a2, 0x1
    ctx->pc = 0x1bbc8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1bbc90: 0x42043  sra         $a0, $a0, 1
    ctx->pc = 0x1bbc90u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 1));
label_1bbc94:
    // 0x1bbc94: 0x872023  subu        $a0, $a0, $a3
    ctx->pc = 0x1bbc94u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bbc98: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1bbc98u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbc9c: 0x44880000  mtc1        $t0, $f0
    ctx->pc = 0x1bbc9cu;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bbca0: 0x0  nop
    ctx->pc = 0x1bbca0u;
    // NOP
    // 0x1bbca4: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbca4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbca8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bbca8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bbcac: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bbcacu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bbcb0: 0x94690008  lhu         $t1, 0x8($v1)
    ctx->pc = 0x1bbcb0u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
label_1bbcb4:
    // 0x1bbcb4: 0x9468000e  lhu         $t0, 0xE($v1)
    ctx->pc = 0x1bbcb4u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1bbcb8: 0x9464000a  lhu         $a0, 0xA($v1)
    ctx->pc = 0x1bbcb8u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x1bbcbc: 0x94a6000e  lhu         $a2, 0xE($a1)
    ctx->pc = 0x1bbcbcu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 14)));
    // 0x1bbcc0: 0x4c00004  bltz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBCC0u;
    {
        const bool branch_taken_0x1bbcc0 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x1BBCC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBCC0u;
            // 0x1bbcc4: 0x9463000c  lhu         $v1, 0xC($v1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbcc0) {
            ctx->pc = 0x1BBCD4u;
            goto label_1bbcd4;
        }
    }
    ctx->pc = 0x1BBCC8u;
    // 0x1bbcc8: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1bbcc8u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbccc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBCCCu;
    {
        const bool branch_taken_0x1bbccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBCD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBCCCu;
            // 0x1bbcd0: 0x468008a0  cvt.s.w     $f2, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbccc) {
            ctx->pc = 0x1BBCF0u;
            goto label_1bbcf0;
        }
    }
    ctx->pc = 0x1BBCD4u;
label_1bbcd4:
    // 0x1bbcd4: 0x63842  srl         $a3, $a2, 1
    ctx->pc = 0x1bbcd4u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 1));
    // 0x1bbcd8: 0x30c60001  andi        $a2, $a2, 0x1
    ctx->pc = 0x1bbcd8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
    // 0x1bbcdc: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbcdcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbce0: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbce0u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbce4: 0x0  nop
    ctx->pc = 0x1bbce4u;
    // NOP
    // 0x1bbce8: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1bbce8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1bbcec: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1bbcecu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1bbcf0:
    // 0x1bbcf0: 0x5000004  bltz        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBCF0u;
    {
        const bool branch_taken_0x1bbcf0 = (GPR_S64(ctx, 8) < 0);
        ctx->pc = 0x1BBCF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBCF0u;
            // 0x1bbcf4: 0x83842  srl         $a3, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbcf0) {
            ctx->pc = 0x1BBD04u;
            goto label_1bbd04;
        }
    }
    ctx->pc = 0x1BBCF8u;
    // 0x1bbcf8: 0x44880800  mtc1        $t0, $f1
    ctx->pc = 0x1bbcf8u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbcfc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBCFCu;
    {
        const bool branch_taken_0x1bbcfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBCFCu;
            // 0x1bbd00: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbcfc) {
            ctx->pc = 0x1BBD1Cu;
            goto label_1bbd1c;
        }
    }
    ctx->pc = 0x1BBD04u;
label_1bbd04:
    // 0x1bbd04: 0x31060001  andi        $a2, $t0, 0x1
    ctx->pc = 0x1bbd04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)1);
    // 0x1bbd08: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbd08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbd0c: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbd0cu;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd10: 0x0  nop
    ctx->pc = 0x1bbd10u;
    // NOP
    // 0x1bbd14: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbd14u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbd18: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbd18u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbd1c:
    // 0x1bbd1c: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1bbd1cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1bbd20: 0x5000004  bltz        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBD20u;
    {
        const bool branch_taken_0x1bbd20 = (GPR_S64(ctx, 8) < 0);
        ctx->pc = 0x1BBD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD20u;
            // 0x1bbd24: 0x46010082  mul.s       $f2, $f0, $f1 (Delay Slot)
        ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd20) {
            ctx->pc = 0x1BBD34u;
            goto label_1bbd34;
        }
    }
    ctx->pc = 0x1BBD28u;
    // 0x1bbd28: 0x44880800  mtc1        $t0, $f1
    ctx->pc = 0x1bbd28u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBD2Cu;
    {
        const bool branch_taken_0x1bbd2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD2Cu;
            // 0x1bbd30: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd2c) {
            ctx->pc = 0x1BBD50u;
            goto label_1bbd50;
        }
    }
    ctx->pc = 0x1BBD34u;
label_1bbd34:
    // 0x1bbd34: 0x83842  srl         $a3, $t0, 1
    ctx->pc = 0x1bbd34u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 8), 1));
    // 0x1bbd38: 0x31060001  andi        $a2, $t0, 0x1
    ctx->pc = 0x1bbd38u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)1);
    // 0x1bbd3c: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbd3cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbd40: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbd40u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd44: 0x0  nop
    ctx->pc = 0x1bbd44u;
    // NOP
    // 0x1bbd48: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbd48u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbd4c: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbd4cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbd50:
    // 0x1bbd50: 0x46020840  add.s       $f1, $f1, $f2
    ctx->pc = 0x1bbd50u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x1bbd54: 0x94a60008  lhu         $a2, 0x8($a1)
    ctx->pc = 0x1bbd54u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1bbd58: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bbd58u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1bbd5c: 0x44070800  mfc1        $a3, $f1
    ctx->pc = 0x1bbd5cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x1bbd60: 0x4c00004  bltz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBD60u;
    {
        const bool branch_taken_0x1bbd60 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x1BBD64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD60u;
            // 0x1bbd64: 0x74600  sll         $t0, $a3, 24 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd60) {
            ctx->pc = 0x1BBD74u;
            goto label_1bbd74;
        }
    }
    ctx->pc = 0x1BBD68u;
    // 0x1bbd68: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1bbd68u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd6c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBD6Cu;
    {
        const bool branch_taken_0x1bbd6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD6Cu;
            // 0x1bbd70: 0x468008a0  cvt.s.w     $f2, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd6c) {
            ctx->pc = 0x1BBD90u;
            goto label_1bbd90;
        }
    }
    ctx->pc = 0x1BBD74u;
label_1bbd74:
    // 0x1bbd74: 0x63842  srl         $a3, $a2, 1
    ctx->pc = 0x1bbd74u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 1));
    // 0x1bbd78: 0x30c60001  andi        $a2, $a2, 0x1
    ctx->pc = 0x1bbd78u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
    // 0x1bbd7c: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbd7cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbd80: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbd80u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd84: 0x0  nop
    ctx->pc = 0x1bbd84u;
    // NOP
    // 0x1bbd88: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1bbd88u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1bbd8c: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1bbd8cu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1bbd90:
    // 0x1bbd90: 0x5200004  bltz        $t1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBD90u;
    {
        const bool branch_taken_0x1bbd90 = (GPR_S64(ctx, 9) < 0);
        ctx->pc = 0x1BBD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD90u;
            // 0x1bbd94: 0x93842  srl         $a3, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd90) {
            ctx->pc = 0x1BBDA4u;
            goto label_1bbda4;
        }
    }
    ctx->pc = 0x1BBD98u;
    // 0x1bbd98: 0x44890800  mtc1        $t1, $f1
    ctx->pc = 0x1bbd98u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbd9c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBD9Cu;
    {
        const bool branch_taken_0x1bbd9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBD9Cu;
            // 0x1bbda0: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbd9c) {
            ctx->pc = 0x1BBDBCu;
            goto label_1bbdbc;
        }
    }
    ctx->pc = 0x1BBDA4u;
label_1bbda4:
    // 0x1bbda4: 0x31260001  andi        $a2, $t1, 0x1
    ctx->pc = 0x1bbda4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)1);
    // 0x1bbda8: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbda8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbdac: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbdacu;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbdb0: 0x0  nop
    ctx->pc = 0x1bbdb0u;
    // NOP
    // 0x1bbdb4: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbdb4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbdb8: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbdb8u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbdbc:
    // 0x1bbdbc: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1bbdbcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1bbdc0: 0x5200004  bltz        $t1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBDC0u;
    {
        const bool branch_taken_0x1bbdc0 = (GPR_S64(ctx, 9) < 0);
        ctx->pc = 0x1BBDC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBDC0u;
            // 0x1bbdc4: 0x46010082  mul.s       $f2, $f0, $f1 (Delay Slot)
        ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbdc0) {
            ctx->pc = 0x1BBDD4u;
            goto label_1bbdd4;
        }
    }
    ctx->pc = 0x1BBDC8u;
    // 0x1bbdc8: 0x44890800  mtc1        $t1, $f1
    ctx->pc = 0x1bbdc8u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbdcc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBDCCu;
    {
        const bool branch_taken_0x1bbdcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBDCCu;
            // 0x1bbdd0: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbdcc) {
            ctx->pc = 0x1BBDF0u;
            goto label_1bbdf0;
        }
    }
    ctx->pc = 0x1BBDD4u;
label_1bbdd4:
    // 0x1bbdd4: 0x93842  srl         $a3, $t1, 1
    ctx->pc = 0x1bbdd4u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 9), 1));
    // 0x1bbdd8: 0x31260001  andi        $a2, $t1, 0x1
    ctx->pc = 0x1bbdd8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)1);
    // 0x1bbddc: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbddcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbde0: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbde0u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbde4: 0x0  nop
    ctx->pc = 0x1bbde4u;
    // NOP
    // 0x1bbde8: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbde8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbdec: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbdecu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbdf0:
    // 0x1bbdf0: 0x46020840  add.s       $f1, $f1, $f2
    ctx->pc = 0x1bbdf0u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x1bbdf4: 0x94a6000a  lhu         $a2, 0xA($a1)
    ctx->pc = 0x1bbdf4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 10)));
    // 0x1bbdf8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bbdf8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1bbdfc: 0x44070800  mfc1        $a3, $f1
    ctx->pc = 0x1bbdfcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x1bbe00: 0x0  nop
    ctx->pc = 0x1bbe00u;
    // NOP
    // 0x1bbe04: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x1bbe04u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1bbe08: 0x4c00004  bltz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBE08u;
    {
        const bool branch_taken_0x1bbe08 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x1BBE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE08u;
            // 0x1bbe0c: 0x1074025  or          $t0, $t0, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe08) {
            ctx->pc = 0x1BBE1Cu;
            goto label_1bbe1c;
        }
    }
    ctx->pc = 0x1BBE10u;
    // 0x1bbe10: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1bbe10u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe14: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBE14u;
    {
        const bool branch_taken_0x1bbe14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE14u;
            // 0x1bbe18: 0x468008a0  cvt.s.w     $f2, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe14) {
            ctx->pc = 0x1BBE38u;
            goto label_1bbe38;
        }
    }
    ctx->pc = 0x1BBE1Cu;
label_1bbe1c:
    // 0x1bbe1c: 0x63842  srl         $a3, $a2, 1
    ctx->pc = 0x1bbe1cu;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 6), 1));
    // 0x1bbe20: 0x30c60001  andi        $a2, $a2, 0x1
    ctx->pc = 0x1bbe20u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
    // 0x1bbe24: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbe24u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbe28: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbe28u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe2c: 0x0  nop
    ctx->pc = 0x1bbe2cu;
    // NOP
    // 0x1bbe30: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1bbe30u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1bbe34: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1bbe34u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1bbe38:
    // 0x1bbe38: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBE38u;
    {
        const bool branch_taken_0x1bbe38 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1BBE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE38u;
            // 0x1bbe3c: 0x43842  srl         $a3, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe38) {
            ctx->pc = 0x1BBE4Cu;
            goto label_1bbe4c;
        }
    }
    ctx->pc = 0x1BBE40u;
    // 0x1bbe40: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1bbe40u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe44: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBE44u;
    {
        const bool branch_taken_0x1bbe44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBE48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE44u;
            // 0x1bbe48: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe44) {
            ctx->pc = 0x1BBE64u;
            goto label_1bbe64;
        }
    }
    ctx->pc = 0x1BBE4Cu;
label_1bbe4c:
    // 0x1bbe4c: 0x30860001  andi        $a2, $a0, 0x1
    ctx->pc = 0x1bbe4cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1bbe50: 0xe63825  or          $a3, $a3, $a2
    ctx->pc = 0x1bbe50u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1bbe54: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x1bbe54u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe58: 0x0  nop
    ctx->pc = 0x1bbe58u;
    // NOP
    // 0x1bbe5c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbe5cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbe60: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbe60u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbe64:
    // 0x1bbe64: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1bbe64u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1bbe68: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBE68u;
    {
        const bool branch_taken_0x1bbe68 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1BBE6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE68u;
            // 0x1bbe6c: 0x46010082  mul.s       $f2, $f0, $f1 (Delay Slot)
        ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe68) {
            ctx->pc = 0x1BBE7Cu;
            goto label_1bbe7c;
        }
    }
    ctx->pc = 0x1BBE70u;
    // 0x1bbe70: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1bbe70u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe74: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBE74u;
    {
        const bool branch_taken_0x1bbe74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBE74u;
            // 0x1bbe78: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbe74) {
            ctx->pc = 0x1BBE98u;
            goto label_1bbe98;
        }
    }
    ctx->pc = 0x1BBE7Cu;
label_1bbe7c:
    // 0x1bbe7c: 0x43042  srl         $a2, $a0, 1
    ctx->pc = 0x1bbe7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x1bbe80: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1bbe80u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1bbe84: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x1bbe84u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1bbe88: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1bbe88u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbe8c: 0x0  nop
    ctx->pc = 0x1bbe8cu;
    // NOP
    // 0x1bbe90: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbe90u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbe94: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbe94u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbe98:
    // 0x1bbe98: 0x46020840  add.s       $f1, $f1, $f2
    ctx->pc = 0x1bbe98u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x1bbe9c: 0x94a4000c  lhu         $a0, 0xC($a1)
    ctx->pc = 0x1bbe9cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1bbea0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bbea0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1bbea4: 0x44050800  mfc1        $a1, $f1
    ctx->pc = 0x1bbea4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1bbea8: 0x0  nop
    ctx->pc = 0x1bbea8u;
    // NOP
    // 0x1bbeac: 0x52a00  sll         $a1, $a1, 8
    ctx->pc = 0x1bbeacu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1bbeb0: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBEB0u;
    {
        const bool branch_taken_0x1bbeb0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1BBEB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBEB0u;
            // 0x1bbeb4: 0xa83025  or          $a2, $a1, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) | GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbeb0) {
            ctx->pc = 0x1BBEC4u;
            goto label_1bbec4;
        }
    }
    ctx->pc = 0x1BBEB8u;
    // 0x1bbeb8: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1bbeb8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbebc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBEBCu;
    {
        const bool branch_taken_0x1bbebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBEBCu;
            // 0x1bbec0: 0x468008a0  cvt.s.w     $f2, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbebc) {
            ctx->pc = 0x1BBEE0u;
            goto label_1bbee0;
        }
    }
    ctx->pc = 0x1BBEC4u;
label_1bbec4:
    // 0x1bbec4: 0x42842  srl         $a1, $a0, 1
    ctx->pc = 0x1bbec4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x1bbec8: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1bbec8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1bbecc: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x1bbeccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1bbed0: 0x44850800  mtc1        $a1, $f1
    ctx->pc = 0x1bbed0u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbed4: 0x0  nop
    ctx->pc = 0x1bbed4u;
    // NOP
    // 0x1bbed8: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1bbed8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1bbedc: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1bbedcu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1bbee0:
    // 0x1bbee0: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBEE0u;
    {
        const bool branch_taken_0x1bbee0 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1BBEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBEE0u;
            // 0x1bbee4: 0x32842  srl         $a1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbee0) {
            ctx->pc = 0x1BBEF4u;
            goto label_1bbef4;
        }
    }
    ctx->pc = 0x1BBEE8u;
    // 0x1bbee8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1bbee8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbeec: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BBEECu;
    {
        const bool branch_taken_0x1bbeec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBEF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBEECu;
            // 0x1bbef0: 0x46800860  cvt.s.w     $f1, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbeec) {
            ctx->pc = 0x1BBF0Cu;
            goto label_1bbf0c;
        }
    }
    ctx->pc = 0x1BBEF4u;
label_1bbef4:
    // 0x1bbef4: 0x30640001  andi        $a0, $v1, 0x1
    ctx->pc = 0x1bbef4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1bbef8: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x1bbef8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1bbefc: 0x44850800  mtc1        $a1, $f1
    ctx->pc = 0x1bbefcu;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bbf00: 0x0  nop
    ctx->pc = 0x1bbf00u;
    // NOP
    // 0x1bbf04: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1bbf04u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1bbf08: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1bbf08u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1bbf0c:
    // 0x1bbf0c: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1bbf0cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1bbf10: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBF10u;
    {
        const bool branch_taken_0x1bbf10 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1BBF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBF10u;
            // 0x1bbf14: 0x46010042  mul.s       $f1, $f0, $f1 (Delay Slot)
        ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbf10) {
            ctx->pc = 0x1BBF24u;
            goto label_1bbf24;
        }
    }
    ctx->pc = 0x1BBF18u;
    // 0x1bbf18: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1bbf18u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bbf1c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BBF1Cu;
    {
        const bool branch_taken_0x1bbf1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBF1Cu;
            // 0x1bbf20: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbf1c) {
            ctx->pc = 0x1BBF40u;
            goto label_1bbf40;
        }
    }
    ctx->pc = 0x1BBF24u;
label_1bbf24:
    // 0x1bbf24: 0x32042  srl         $a0, $v1, 1
    ctx->pc = 0x1bbf24u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1bbf28: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1bbf28u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1bbf2c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1bbf2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1bbf30: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bbf30u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bbf34: 0x0  nop
    ctx->pc = 0x1bbf34u;
    // NOP
    // 0x1bbf38: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bbf38u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bbf3c: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x1bbf3cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_1bbf40:
    // 0x1bbf40: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1bbf40u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1bbf44: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbf44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbf48: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1bbf48u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1bbf4c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1bbf4cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1bbf50: 0x0  nop
    ctx->pc = 0x1bbf50u;
    // NOP
    // 0x1bbf54: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x1bbf54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x1bbf58: 0xac236614  sw          $v1, 0x6614($at)
    ctx->pc = 0x1bbf58u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26132), GPR_U32(ctx, 3));
label_1bbf5c:
    // 0x1bbf5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBF5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            case 0x1BBB94u: goto label_1bbb94;
            case 0x1BBBB8u: goto label_1bbbb8;
            case 0x1BBBF8u: goto label_1bbbf8;
            case 0x1BBC00u: goto label_1bbc00;
            case 0x1BBC18u: goto label_1bbc18;
            case 0x1BBC54u: goto label_1bbc54;
            case 0x1BBC80u: goto label_1bbc80;
            case 0x1BBC94u: goto label_1bbc94;
            case 0x1BBCB4u: goto label_1bbcb4;
            case 0x1BBCD4u: goto label_1bbcd4;
            case 0x1BBCF0u: goto label_1bbcf0;
            case 0x1BBD04u: goto label_1bbd04;
            case 0x1BBD1Cu: goto label_1bbd1c;
            case 0x1BBD34u: goto label_1bbd34;
            case 0x1BBD50u: goto label_1bbd50;
            case 0x1BBD74u: goto label_1bbd74;
            case 0x1BBD90u: goto label_1bbd90;
            case 0x1BBDA4u: goto label_1bbda4;
            case 0x1BBDBCu: goto label_1bbdbc;
            case 0x1BBDD4u: goto label_1bbdd4;
            case 0x1BBDF0u: goto label_1bbdf0;
            case 0x1BBE1Cu: goto label_1bbe1c;
            case 0x1BBE38u: goto label_1bbe38;
            case 0x1BBE4Cu: goto label_1bbe4c;
            case 0x1BBE64u: goto label_1bbe64;
            case 0x1BBE7Cu: goto label_1bbe7c;
            case 0x1BBE98u: goto label_1bbe98;
            case 0x1BBEC4u: goto label_1bbec4;
            case 0x1BBEE0u: goto label_1bbee0;
            case 0x1BBEF4u: goto label_1bbef4;
            case 0x1BBF0Cu: goto label_1bbf0c;
            case 0x1BBF24u: goto label_1bbf24;
            case 0x1BBF40u: goto label_1bbf40;
            case 0x1BBF5Cu: goto label_1bbf5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBF64u;
    // 0x1bbf64: 0x0  nop
    ctx->pc = 0x1bbf64u;
    // NOP
    // 0x1bbf68: 0x0  nop
    ctx->pc = 0x1bbf68u;
    // NOP
    // 0x1bbf6c: 0x0  nop
    ctx->pc = 0x1bbf6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
