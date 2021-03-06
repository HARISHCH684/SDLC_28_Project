/*
 @Author
*/

#include "unity.h"
#include "passwordUsernameFormatChecker.h"
#include "masterAccountFunctions.h"
#include "credentialFunctions.h"
#define PROJECT_NAME "TextPad"

/* Prototypes for all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void);
void test_containNumber(void);
void test_containLowerCaseLetter(void);
void test_containUpperCaseLetter(void);
void test_passwordFormatCheck(void);
void test_usernameFormatCheck(void);



/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_createMasteUserAccount(void);
void test_deleteMasterUserAccount(void);
void test_userAccountExist(void);
void test_verifyMasterUserAccount(void);
void test_modifyMasterUsername(void);
void test_modifyMasterPassword(void);



/********************************
 * Filename -> credentialFunctions.c
*/
void test_addNewCredential(void);
void test_showAllCredentials(void);
void test_showAllSortedCredentials(void);
void test_deleteAllCredentials(void);
void test_deleteCredential(void);
void test_credentialExist(void);

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown() {}


/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */

  /********************************
 * Filename -> passwordUsernameFormatChecker.c
 */
RUN_TEST(test_containSpecialCharacter);
  RUN_TEST(test_containNumber);
  RUN_TEST(test_containLowerCaseLetter);
  RUN_TEST(test_containUpperCaseLetter);
  RUN_TEST(test_passwordFormatCheck);
  RUN_TEST(test_usernameFormatCheck);


  /********************************
 * Filename -> masterAccountFunctions.c
*/
   RUN_TEST(test_createMasteUserAccount);
  RUN_TEST(test_deleteMasterUserAccount);
  RUN_TEST(test_userAccountExist);
  RUN_TEST(test_verifyMasterUserAccount);
  RUN_TEST(test_modifyMasterUsername);
  RUN_TEST(test_modifyMasterPassword);
  

  /********************************
 * Filename -> credentialFunctions.c
*/
  RUN_TEST(test_addNewCredential);
  RUN_TEST(test_showAllCredentials);
  RUN_TEST(test_showAllSortedCredentials);
  RUN_TEST(test_deleteAllCredentials);
  RUN_TEST(test_deleteCredential);
  RUN_TEST(test_credentialExist);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void)
{
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankit$kumar"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankitkumar#"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("@ankit$kumar*"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumars d"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("asdfsad"));
}

void test_containNumber(void)
{
  TEST_ASSERT_EQUAL(true, containNumber("ankit23kumar"));
  TEST_ASSERT_EQUAL(true, containNumber("ankitkumar23"));
  TEST_ASSERT_EQUAL(true, containNumber("12ankitkumar"));
  TEST_ASSERT_EQUAL(false, containNumber("ankitkumar"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FS23D$#$@!#!@"));
}

void test_containLowerCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("andaskjds"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITUMAr"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("aNKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$er#$@!#!@"));
}

void test_containUpperCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ankitkumaR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("Ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
}

void test_passwordFormatCheck(void)
{
  TEST_ASSERT_EQUAL(true, passwordFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@NKITKUMAR123"));
}

void test_usernameFormatCheck()
{
  TEST_ASSERT_EQUAL(true, usernameFormatCheck("ankit123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@NKITKUMAR123"));
}

/********************************

* Filename -> masterAccountFunctions.c
*/

void test_createMasteUserAccount(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, createMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, createMasterUserAccount(NULL, NULL));
  TEST_ASSERT_EQUAL(EMPTY_STRING,createMasterUserAccount("",""));
  TEST_ASSERT_EQUAL(SUCCESS, createMasterUserAccount("Anurag", "Anu#12"));

}
void test_deleteMasterUserAccount(void)
{
  createMasterUserAccount("Ankit123", "Ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, deleteMasterUserAccount());

  TEST_ASSERT_EQUAL(FAILURE, deleteMasterUserAccount());
}
void test_userAccountExist(void)
{
  deleteMasterUserAccount();
  TEST_ASSERT_EQUAL(false, masterUserAccountExist());

  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, masterUserAccountExist());
}
void test_verifyMasterUserAccount(void)
{
  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));
  TEST_ASSERT_EQUAL(false,verifyMasterUserAccount(NULL,NULL));
  TEST_ASSERT_EQUAL(false,verifyMasterUserAccount("",""));

  createMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@");

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));
  TEST_ASSERT_EQUAL(false,verifyMasterUserAccount(NULL,NULL));
  TEST_ASSERT_EQUAL(false,verifyMasterUserAccount("",""));
}
void test_modifyMasterPassword(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterPassword("new_password"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("old_username", "new_password"));

  TEST_ASSERT_EQUAL(NULL_PTR,modifyMasterPassword(NULL));
  TEST_ASSERT_EQUAL(EMPTY_STRING,modifyMasterPassword(""));
}
void test_modifyMasterUsername(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterUsername("new_username"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("new_username", "old_password"));

  TEST_ASSERT_EQUAL(NULL_PTR,modifyMasterUsername(NULL));
  TEST_ASSERT_EQUAL(EMPTY_STRING,modifyMasterUsername(""));
}


/********************************
 * Filename -> credentialFunctions.c
*/

void test_addNewCredential(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("facebook", "User1", "Pass123"));
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("twitter", "User2", "Pass123"));
  TEST_ASSERT_EQUAL(EMPTY_STRING, addNewCredential("", "", "Pass123"));
  TEST_ASSERT_EQUAL(NULL_PTR, addNewCredential("as", "User5", NULL));

  deleteAllCredentials();
}
void test_showAllCredentials(void)
{
  addNewCredential("facebook", "User1", "Pass123");
  addNewCredential("Amcat", "User2", "Pass123");
  TEST_ASSERT_EQUAL(SUCCESS, showAllCredentials());
  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, showAllCredentials());

  deleteAllCredentials();
}

void test_showAllSortedCredentials(void)
{
  addNewCredential("facebook", "User1", "Pass123");
  addNewCredential("twitter", "User2", "Pass213");
  addNewCredential("Amcat", "User3", "Pass312");
  TEST_ASSERT_EQUAL(SUCCESS, showAllSortedCredentials());
  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, showAllSortedCredentials());

  deleteAllCredentials();
}
void test_deleteAllCredentials(void)
{
  addNewCredential("facebook", "Ankit", "ankit123");
  addNewCredential("Apple","Anurag","Anu");
  addNewCredential("Window","Abcd","Ab");
  TEST_ASSERT_EQUAL(SUCCESS, deleteAllCredentials());
  TEST_ASSERT_EQUAL(FAILURE, deleteAllCredentials());
}
void test_deleteCredential(void)
{
  addNewCredential("Facebook","Ab","Anu");
  addNewCredential("ABCD","anu","Anu#1234");
  TEST_ASSERT_EQUAL(SUCCESS,deleteCredential("Facebook","Ab"));
  TEST_ASSERT_EQUAL(FAILURE,deleteCredential("abcd","Ab"));
  addNewCredential("applock","at","at#123");
  TEST_ASSERT_EQUAL(FAILURE,deleteCredential("ABCD","anurag"));  
  TEST_ASSERT_EQUAL(NULL_PTR,deleteCredential(NULL,NULL));
  TEST_ASSERT_EQUAL(EMPTY_STRING,deleteCredential("",""));
  TEST_ASSERT_EQUAL(FAILURE,deleteCredential("APPPPLE","adad"));
  
}

void test_credentialExist(void)
{
  addNewCredential("twitter", "Ankit", "ankit123");
  addNewCredential("Random Organisation", "Ankit Kumar", "@nkit123");

  TEST_ASSERT_EQUAL(true, credentialExist("twitter", "Ankit"));
  TEST_ASSERT_EQUAL(true, credentialExist("Random Organisation", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("twitter", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));

  TEST_ASSERT_EQUAL(false, credentialExist(NULL, "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("Ankit Kumar", NULL));
  TEST_ASSERT_EQUAL(false, credentialExist("Ankit Kumar", ""));

  // creeating empty file
  FILE *test_file = fopen(CREDENTIAL_FILE, "w");
  fclose(test_file);

  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));

  deleteAllCredentials();
  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));
}